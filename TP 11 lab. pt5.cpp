#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno {
private:
    string nombre;
    double nota1;
    double nota2;
    double nota3;
    int edad;
    string estado;

    void actualizarEstado() {
        if (calcularPromedio() >= 7.0) {
            estado = "Aprobado";
        } else {
            estado = "Desaprobado";
        }
    }

public:
    Alumno(string nombre, double nota1, double nota2, double nota3, int edad)
        : nombre(nombre), nota1(nota1), nota2(nota2), nota3(nota3), edad(edad) {
        actualizarEstado();
    }

    string getNombre() const { return nombre; }
    double getNota1() const { return nota1; }
    double getNota2() const { return nota2; }
    double getNota3() const { return nota3; }
    int getEdad() const { return edad; }
    string getEstado() const { return estado; }

    double calcularPromedio() const { return (nota1 + nota2 + nota3) / 3; }
    double getNotaMasAlta() const { return max(max(nota1, nota2), nota3); }
    double getNotaMasBaja() const { return min(min(nota1, nota2), nota3); }
};

void buscarAlumno(const vector<Alumno>& alumnos, const string& nombreBuscado) {
    bool encontrado = false;
    for (size_t i = 0; i < alumnos.size(); i++) {
        const Alumno& alumno = alumnos[i];
        if (alumno.getNombre() == nombreBuscado) {
            cout << "\nAlumno encontrado:" << endl;
            cout << "Nombre: " << alumno.getNombre() << endl;
            cout << "Edad: " << alumno.getEdad() << endl;
            cout << "Nota 1: " << alumno.getNota1() << endl;
            cout << "Nota 2: " << alumno.getNota2() << endl;
            cout << "Nota 3: " << alumno.getNota3() << endl;
            cout << "Promedio: " << alumno.calcularPromedio() << endl;
            cout << "Estado: " << alumno.getEstado() << endl;
            cout << "Nota m�s alta: " << alumno.getNotaMasAlta() << endl;
            cout << "Nota m�s baja: " << alumno.getNotaMasBaja() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Alumno no encontrado." << endl;
    }
}

double calcularPromedioGeneral(const vector<Alumno>& alumnos) {
    double sumaPromedios = 0.0;
    for (size_t i = 0; i < alumnos.size(); i++) {
        sumaPromedios += alumnos[i].calcularPromedio();
    }
    return alumnos.empty() ? 0.0 : sumaPromedios / alumnos.size();
}

int main() {
    vector<Alumno> alumnos;
    string nombre;
    double nota1, nota2, nota3;
    int edad;
    int numAlumnos;

    cout << "Ingrese el n�mero de alumnos: ";
    cin >> numAlumnos;

    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese el nombre del alumno: ";
        cin >> nombre;
        cout << "Ingrese la edad del alumno: ";
        cin >> edad;
        cout << "Ingrese la nota 1 del alumno: ";
        cin >> nota1;
        cout << "Ingrese la nota 2 del alumno: ";
        cin >> nota2;
        cout << "Ingrese la nota 3 del alumno: ";
        cin >> nota3;
        alumnos.push_back(Alumno(nombre, nota1, nota2, nota3, edad));
    }

    cout << "\nDatos de los alumnos:" << endl;
    for (size_t i = 0; i < alumnos.size(); i++) {
        const Alumno& alumno = alumnos[i];
        cout << "Nombre: " << alumno.getNombre() << endl;
        cout << "Edad: " << alumno.getEdad() << endl;
        cout << "Nota 1: " << alumno.getNota1() << endl;
        cout << "Nota 2: " << alumno.getNota2() << endl;
        cout << "Nota 3: " << alumno.getNota3() << endl;
        cout << "Promedio: " << alumno.calcularPromedio() << endl;
        cout << "Estado: " << alumno.getEstado() << endl;
        cout << "Nota m�s alta: " << alumno.getNotaMasAlta() << endl;
        cout << "Nota m�s baja: " << alumno.getNotaMasBaja() << endl;
        cout << endl;
    }

    double promedioGeneral = calcularPromedioGeneral(alumnos);
    cout << "Promedio general de todos los alumnos: " << promedioGeneral << endl;

    string nombreBuscado;
    cout << "Ingrese el nombre del alumno a buscar: ";
    cin >> nombreBuscado;
    buscarAlumno(alumnos, nombreBuscado);

    return 0;
}

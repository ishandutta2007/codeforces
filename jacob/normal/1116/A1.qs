namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (x : Qubit[]) : Unit {
        PrepareUniformSuperposition(3, BigEndian(x));
    }

    operation SingleArgumentSolve(x: Qubit[]) : Unit {
        body (...) {
        }
    }
}
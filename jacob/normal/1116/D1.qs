namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[]) : Unit {
        body (...) {
            H(Head(x));
            // Controlled X(x, y);
        }
        adjoint auto;
    }

    operation SingleArgumentSolve(x: Qubit[]) : Unit {
        body (...) {
            // Solve(x[1 .. Length(x) - 1], Head(x));
            Solve(x);
        }
        adjoint auto;
    }
}
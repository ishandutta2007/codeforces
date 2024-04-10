namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            for (i in 1..n-1) {
                for (j in 0..i-1) {
                    Controlled R([x[i]], (PauliX, 0.5, x[j]));
                }
            }
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
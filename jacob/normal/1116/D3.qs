namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[]) : Unit {
        body (...) {
            let n = Length(x);
            for (i in 1..n-1) {
                Controlled X([x[0]], x[i]);
            }
            H(x[0]);
            for (i in 1..n-1) {
                Controlled X([x[0]], x[i]);
            }
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
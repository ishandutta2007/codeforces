namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Helper(x: Qubit[]) : Unit {
        body (...) {
            for (i in 0 .. Length(x) - 2) {
                CNOT(x[i+1], x[i]);
            }
        }

        adjoint auto;
    }

    operation Solve(x : Qubit[], y: Qubit) : Unit {
        body (...) {
            Helper(x);
            Controlled X(Most(x), y);
            Adjoint Helper(x);
        }

        adjoint auto;
    }
}
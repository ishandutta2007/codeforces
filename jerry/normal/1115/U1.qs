namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body {
            mutable n = Length(x);
            if (n == 1) {
                X(y);
            } else {
                for (i in 1..n-1) {
                    CNOT(x[i], x[i-1]);
                }
                Controlled X(x[0..n-2], y);
                for (i in 1..n-1) {
                    CNOT(x[n-i], x[n-i-1]);
                }
            }
        }
        adjoint auto;
    }
}
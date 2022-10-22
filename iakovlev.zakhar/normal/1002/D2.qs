namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            for (i in 0 .. Length(x) - 1) {
                if (b[i] > 0) {
                    CNOT(x[i], y);
                } else {
                    CNOT(x[i], y);
                    X(y);
                }
            }
        }
    }
}
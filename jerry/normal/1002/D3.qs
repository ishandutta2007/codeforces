namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            CNOT(x[2], x[1]);
            X(x[1]);
            (Controlled SWAP)([x[1]], (x[0], x[2]));

            CNOT(x[0], y);

            (Controlled SWAP)([x[1]], (x[0], x[2]));
            X(x[1]);
            CNOT(x[2], x[1]);
        }
    }
}
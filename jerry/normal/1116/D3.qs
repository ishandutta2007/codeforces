namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        mutable n = Length(qs);
        Controlled ApplyToEachC([qs[0]], (X, qs[1..n-1]));
        H(qs[0]);
        for (i in 1..n-1) {
            CNOT(qs[0], qs[i]);
        }
    }
}
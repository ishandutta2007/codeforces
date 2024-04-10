namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        mutable n = Length(qs);
        ApplyToEach(X, qs[0..n-2]);
        Controlled ApplyToEachC([qs[n-1]], (X, qs[0..n-2]));
        if (n >= 3) {
            for (i in 0..n-3) {
                ApplyToEach(X, qs[0..n-i-3]);
                Controlled X(qs[0..n-i-3], qs[n-i-2]);
                ApplyToEach(X, qs[0..n-i-3]);
            }
        }
        X(qs[0]);
        Controlled ApplyToEachC([qs[n-1]], (X, qs[0..n-2]));

        Controlled ApplyToEachC([qs[0]], (X, qs[1..n-1]));
        H(qs[0]);
        for (i in 1..n-1) {
            CNOT(qs[0], qs[i]);
        }
    }
}
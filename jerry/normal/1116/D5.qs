namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation D3 (qs : Qubit[]) : Unit {
        body {
            mutable n = Length(qs);
            Controlled ApplyToEachC([qs[0]], (X, qs[1..n-1]));
            H(qs[0]);
            for (i in 1..n-1) {
                CNOT(qs[0], qs[i]);
            }
        }
        controlled auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
        using (tmp = Qubit[1]) {
            CNOT(qs[1], tmp[0]);
            CNOT(qs[2], tmp[0]);
            X(qs[0]);
            Controlled ApplyToEachC([tmp[0], qs[0]], (X, qs[1..2]));
            X(qs[0]);
            CNOT(qs[1], tmp[0]);
            CNOT(qs[2], tmp[0]);
        }
        using (tmp = Qubit[1]) {
            CNOT(qs[1], tmp[0]);
            CNOT(qs[2], tmp[0]);
            X(tmp[0]);
            Controlled D3(tmp, qs);
            CNOT(qs[1], tmp[0]);
            CNOT(qs[2], tmp[0]);
            X(tmp[0]);
        }
        H(qs[0]);
    }
}
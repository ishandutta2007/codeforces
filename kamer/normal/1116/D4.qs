namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation PlusOne(qs : Qubit[]) : Unit
        is Ctl + Adj {
        X(qs[0]);
        for (i in 0..Length(qs)-2) {
            ApplyToEachCA(X, qs[0..i]);
            Controlled X(qs[0..i], qs[i + 1]);
            ApplyToEachCA(X, qs[0..i]);
        }
    }

    operation MinusOne(qs : Qubit[]) : Unit
        is Ctl + Adj {
        X(qs[0]);
        for (i in 0..Length(qs)-2) {
            Controlled X(qs[0..i], qs[i + 1]);
        }
    }

    operation D3 (qs : Qubit[]) : Unit {
        // your code here
        Controlled ApplyToEachC([qs[0]], (X, qs[1..Length(qs)-1]));
        H(qs[0]);
        for (i in 1..Length(qs)-1) {
            CNOT(qs[0], qs[i]);
        }
    }

    operation D4 (qs : Qubit[]) : Unit {
        let n = Length(qs);
        ApplyToEach(X, qs[0..n - 2]);
        Controlled PlusOne([qs[n - 1]], qs[0..n - 2]);
        X(qs[n - 1]);
        Controlled MinusOne([qs[n - 1]], qs[0..n - 2]);
        X(qs[n - 1]);
        D3(qs);
    }

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
        D4(qs);
    }
}
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        using (x = Qubit[1]) {
            for (i in 0..n-1) {
                X(qs[i]);
            }
            X(x[0]);
            for (j in 0..20) {
                if (M(x[0]) == One) {
                    for (i in 0..n-1) {
                        X(qs[i]);
                    }
                    X(x[0]);
                    for (i in 0..n-1) {
                        H(qs[i]);
                    }
                    (Controlled X)(qs, x[0]);
                }
            }
        }
    }
}
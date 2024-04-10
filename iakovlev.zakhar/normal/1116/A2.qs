namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        let n = Length(qs);
        if (n == 2) {
            H(qs[0]);
            H(qs[1]);
        } else {
            using(x = Qubit[2]) {
                H(x[0]);
                H(x[1]);
                
                X(x[0]);
                X(x[1]);
                for (i in 0 .. n - 1) {
                    if (bits[0][i]) {
                        CCNOT(x[0], x[1], qs[i]);
                    }
                }
                X(x[0]);
                X(x[1]);
                
                X(x[1]);
                for (i in 0 .. n - 1) {
                    if (bits[1][i]) {
                        CCNOT(x[0], x[1], qs[i]);
                    }
                }
                X(x[1]);
                
                X(x[0]);
                for (i in 0 .. n - 1) {
                    if (bits[2][i]) {
                        CCNOT(x[0], x[1], qs[i]);
                    }
                }
                X(x[0]);
                
                for (i in 0 .. n - 1) {
                    if (bits[3][i]) {
                        CCNOT(x[0], x[1], qs[i]);
                    }
                }
                
                for (i in 0 .. n - 1) {
                    if (!bits[1][i]) {
                        X(qs[i]);
                    }
                }
                (Controlled X)(qs, x[0]);
                for (i in 0 .. n - 1) {
                    if (!bits[1][i]) {
                        X(qs[i]);
                    }
                }
                
                for (i in 0 .. n - 1) {
                    if (!bits[2][i]) {
                        X(qs[i]);
                    }
                }
                (Controlled X)(qs, x[1]);
                for (i in 0 .. n - 1) {
                    if (!bits[2][i]) {
                        X(qs[i]);
                    }
                }
                
                for (i in 0 .. n - 1) {
                    if (!bits[3][i]) {
                        X(qs[i]);
                    }
                }
                (Controlled X)(qs, x[0]);
                (Controlled X)(qs, x[1]);
                for (i in 0 .. n - 1) {
                    if (!bits[3][i]) {
                        X(qs[i]);
                    }
                }
                
            }
        }
    }
}
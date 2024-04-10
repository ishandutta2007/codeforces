namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qs : Qubit[]) : Unit {
        using(x = Qubit[1]) {
            X(x[0]);
            for (i in 0..100) {
                if (M(x[0]) == One) {
                    Reset(qs[0]);
                    Reset(qs[1]);
                    Reset(x[0]);
                    H(qs[0]);
                    H(qs[1]);
                    CCNOT(qs[0], qs[1], x[0]);
                }
            }
            X(qs[0]);
            X(qs[1]);
            Reset(x[0]);
        }
    }
}
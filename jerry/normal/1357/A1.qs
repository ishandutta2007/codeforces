namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            X(qs[0]);
            if (M(qs[1]) == One) {
                X(qs[1]);
                return 0;
            } else {
                return 1;
            }
        }
    }
}
namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            unitary(q);
            Z(q);
            unitary(q);
            if (M(q) == One) {
                X(q);
                return 0;
            } else {
                return 1;
            }
        }
    }
}
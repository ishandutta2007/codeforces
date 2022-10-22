namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        using (q = Qubit()) {
            H(q);
            unitary(q);
            H(q);
            if (M(q) == Zero) {
                return 0;
            } else {
                X(q);
                return 1;
            }
        }
    }
}
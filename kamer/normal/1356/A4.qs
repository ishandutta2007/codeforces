namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        using (q = Qubit[2]) {
            unitary(q);
            if (M(q[1]) == Zero) {
                return 1;
            } else {
                X(q[1]);
                return 0;
            }
        }
    }
}
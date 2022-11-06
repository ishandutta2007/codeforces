namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve(u : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((q1, q2) = (Qubit(), Qubit())) {
            X(q1);
            X(q2);
            u([q1, q2]);
            Reset(q2);
            let q = M(q1);
            Reset(q1);
            if (q == Zero) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}
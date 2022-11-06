namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve(u : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using ((q1, q2) = (Qubit(), Qubit())) {
            X(q1);
            u([q1, q2]);
            if (M(q1) != One or M(q2) != Zero) {
                set ret += 1;
            }
            Reset(q1);
            Reset(q2);
            X(q2);
            u([q1, q2]);
            if (M(q1) != Zero or M(q2) != One) {
                set ret += 2;
            }
            Reset(q1);
            Reset(q2);
        }
        return ret;
    }
}
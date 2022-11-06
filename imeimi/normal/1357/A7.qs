namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Solve(u : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ret = 0;
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            Controlled u([q1], q2);
            Controlled u([q1], q2);
            H(q1);
            set ret += M(q1) == One ? 1 | 0;
            Reset(q1);
        }
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            Controlled u([q1], q2);
            if (ret == 0) {
                Controlled S([q1], q2);
            }
            Controlled X([q1], q2);
            H(q1);
            set ret += M(q1) == Zero ? 2 | 0;
            Reset(q1);
        }
        return ret;
    }
}
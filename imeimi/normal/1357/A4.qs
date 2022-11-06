namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Solve(u : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            H(q2);
            Controlled u([q1], (2. * PI(), q2));
            H(q1);
            let r = M(q1);
            Reset(q1);
            Reset(q2);
            return r == One ? 0 | 1;
        }
    }
}
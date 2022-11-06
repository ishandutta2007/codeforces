namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Solve(qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            repeat {
                for (i in qs) { H(i); }
                Controlled X(qs, q);
            }
            until (M(q) == Zero)
            fixup {
                ResetAll(qs);
                Reset(q);
            }
            Reset(q);
        }
    }
}
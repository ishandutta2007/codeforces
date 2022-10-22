namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            H(qs[1]);
            H(q);
            Controlled X([q], qs[0]);
            X(qs[0]);
            Controlled X(qs, q);
            X(qs[0]);
            if (M(q) == One) {
                X(q);
            } else {
                Solve(qs);
            }
        }
    }
}
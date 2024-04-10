namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        // your code here
        for (q in qs) {
            H(q);
        }
        using (q = Qubit()) {
            Controlled X(qs, q);
            if (M(q) == One) {
                X(q);
                for (s in qs) {
                    X(s);
                }
                Solve(qs);
            }
        }
    }
}
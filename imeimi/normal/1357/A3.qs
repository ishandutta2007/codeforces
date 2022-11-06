namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve(u : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            u(q);
            X(q);
            u(q);
            let r = M(q);
            Reset(q);
            if (r == One) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}
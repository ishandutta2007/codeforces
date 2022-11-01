namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            H(q[0]); H(q[1]);
            Controlled Z([q[0]], q[1]);
            Controlled unitary([q[0]], q[1]);
            H(q[0]); H(q[1]);
            if (M(q[0]) == One) {
                X(q[0]);
                return 1;
            } else {
                return 0;
            }
        }
    }
}
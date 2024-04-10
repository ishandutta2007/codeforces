namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            H(q[0]); H(q[1]);
            Controlled unitary([q[0]], (2.0*PI(), q[1]));
            H(q[0]); H(q[1]);
            if (M(q[0]) == One) {
                X(q[0]);
                return 0;
            } else {
                return 1;
            }
        }
    }
}
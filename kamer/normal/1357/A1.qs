namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        using (q = Qubit[2]) {
            X(q[0]);
            unitary(q);
            let m1 = M(q[0]);
            let m2 = M(q[1]);
            X(q[0]);
            if (m2 == One) {
                X(q[1]);
                return 0;
            } else {
                return 1;
            }
        }
    }
}
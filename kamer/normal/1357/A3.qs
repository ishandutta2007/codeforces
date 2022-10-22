namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            X(q[0]);
            unitary(q[0]);
            unitary(q[1]);
            let m1 = M(q[0]);
            let m2 = M(q[1]);
            if (m1 != m2) {
                if (m1 == One) {
                    X(q[0]);
                }
                if (m2 == One) {
                    X(q[1]);
                }
                return 1;
            } else {
                if (m1 == One) {
                    X(q[0]);
                }
                if (m2 == One) {
                    X(q[1]);
                }
                return 0;
            }

        }
    }
}
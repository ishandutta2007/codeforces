namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        using (q = Qubit[2]) {
            X(q[0]);
            X(q[1]);
            unitary(q);
            let m1 = M(q[0]);
            let m2 = M(q[1]);
            if (m1 == Zero) {
                X(q[1]);
                return 2;
            } elif (m2 == Zero) {
                X(q[0]);
                return 1;
            } else {
                X(q[0]);
                X(q[1]);
                using (s = Qubit[2]) {
                    X(s[0]);
                    unitary(s);
                    let m3 = M(s[0]);
                    if (m3 == One) {
                        X(s[0]);
                        return 0;
                    } else {
                        X(s[1]);
                        return 3;
                    }
                }
            }
        }
    }
}
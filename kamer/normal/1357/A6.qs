namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            unitary(q[1]);
            CNOT(q[0], q[1]);
            H(q[0]);
            let m0 = M(q[0]);
            let m1 = M(q[1]);
            if (m0 == Zero and m1 == Zero) {
                return 0;
            } elif (m0 == Zero and m1 == One) {
                X(q[1]);
                return 1;
            } elif (m0 == One and m1 == Zero) {
                X(q[0]);
                return 3;
            } else {
                X(q[0]);
                X(q[1]);
                return 2;
            }
        }
    }
}
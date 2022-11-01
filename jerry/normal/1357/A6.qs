namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0], q[1]);
            unitary(q[0]);
            CNOT(q[0], q[1]);
            H(q[0]);
            if (MResetZ(q[0]) == One) {
                return MResetZ(q[1]) == One ? 2 | 3;
            } else {
                return MResetZ(q[1]) == One ? 1 | 0;
            }
        }
    }
}
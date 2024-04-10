namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[3]) {
            ApplyToEach(H, qs);
            Controlled Y([qs[0]], (qs[2]));
            Controlled unitary([qs[0]], (qs[2]));
            Controlled unitary([qs[1]], (qs[2]));
            Controlled unitary([qs[1]], (qs[2]));
            ApplyToEach(H, qs);
            if (MResetZ(qs[1]) == One) {
                return MResetY(qs[0]) == One ? 1 | 3;
            } else {
                return MResetZ(qs[0]) == One ? 2 | 0;
            }
        }
    }
}
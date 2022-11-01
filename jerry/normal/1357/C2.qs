namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let n = Length(qs);
        using (q = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                for (i in 0..n-1) {
                    CNOT(qs[i], q);
                }
                if (parity == 1) {
                    X(q);
                }
            } until(M(q) == Zero)
            fixup {
                ResetAll(qs);
                X(q);
            }
        }
    }
}
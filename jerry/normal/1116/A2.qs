namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        mutable n = Length(qs);
        using (eq = Qubit[4]) {
            H(eq[0]); CNOT(eq[0], eq[2]); X(eq[2]);
            Controlled H([eq[0]], eq[1]); CNOT(eq[1], eq[0]);
            Controlled H([eq[2]], eq[3]); CNOT(eq[3], eq[2]);
            for (j in 0..3) {
                for (i in 0..n-1) {
                    if (bits[j][i]) {
                        CNOT(eq[j], qs[i]);
                    }
                }
            }
            for (j in 0..3) {
                for (i in 0..n-1) {
                    if (!bits[j][i]) {
                        X(qs[i]);
                    }
                }
                Controlled X(qs, eq[j]);
                for (i in 0..n-1) {
                    if (!bits[j][i]) {
                        X(qs[i]);
                    }
                }
            }
        }
    }
}
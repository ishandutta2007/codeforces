namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        using (q = Qubit[2]) {
            ApplyToEach(H, q);
            for (i in 0..3) {
                let bitmask = IntAsBoolArray(i, 2);
                for (j in 0..Length(bits[i])-1) {
                    if (bits[i][j]) {
                        (ControlledOnBitString(bitmask, X))(q, qs[j]);
                    }
                }
            }

            (ControlledOnBitString(bits[1], X))(qs, q[0]);
            (ControlledOnBitString(bits[2], X))(qs, q[1]);
            (ControlledOnBitString(bits[3], X))(qs, q[0]);
            (ControlledOnBitString(bits[3], X))(qs, q[1]);
        }
    }
}
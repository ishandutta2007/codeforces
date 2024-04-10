namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int {
        (Controlled Rz)([qs[1]], (4.188790205, qs[2]));
        (Controlled Rz)([qs[2]], (-4.188790205, qs[1]));
        X(qs[0]);
        X(qs[1]);
        CCNOT(qs[0], qs[1], qs[2]);
        X(qs[0]);
        X(qs[1]);
        (ControlledOnInt(0, H))([qs[0]], qs[1]);
        Ry(-1.230959417, qs[0]);
        if (M(qs[0]) == One) {
            return 1;
        }
        if (M(qs[1]) == One) {
            return 1;
        }
        if (M(qs[2]) == One) {
            return 1;
        }
        return 0;
    }
}
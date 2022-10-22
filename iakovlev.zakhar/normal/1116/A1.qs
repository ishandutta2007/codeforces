namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(1.230959417, qs[0]);
        (ControlledOnInt(0, H))([qs[0]], qs[1]);

    }
}
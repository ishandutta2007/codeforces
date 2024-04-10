namespace Solution {
open Microsoft.Quantum.Primitive;
open Microsoft.Quantum.Canon;
open Microsoft.Quantum.Math;

operation Solve(qs : Qubit[]) : Unit {
    Ry(ArcCos(Sqrt(2.0/3.0)) * 2.0, qs[0]);
    X(qs[0]);
    Controlled H([qs[0]], qs[1]);
    X(qs[0]);
}
}
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        R(PauliY, 1.9106332362490184, qs[1]); // lmao what are the odds that this works
        Controlled H([qs[1]], qs[0]);
        X(qs[1]);
    }
}
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation BetterSolve(qs : Qubit[], n : Int) : Unit {
        if (n > 1) {
            Controlled ApplyToEachC(qs[n-1..Length(qs)-1], (H, qs[0..n-2]));
            X(qs[n-1]);
            BetterSolve(qs, n-1);
            X(qs[n-1]);
        }
    }

    operation Solve (qs : Qubit[]) : Unit {
        BetterSolve(qs, Length(qs));
    }
}
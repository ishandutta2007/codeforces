namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        // your code here
        for (i in 0..Length(qs) - 2) {
            H(qs[i]);
            Controlled X([qs[i]], qs[Length(qs)-1]);
        }
        if (parity == 1) {
            X(qs[Length(qs) - 1]);
        }
    }
}
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let n = Length(qs);
        for (i in 0..n-2) {
            H(qs[i]);
            CNOT(qs[i], qs[n - 1]);
        }
        if (parity == 1) {
            X(qs[n - 1]);
        }
    }
}
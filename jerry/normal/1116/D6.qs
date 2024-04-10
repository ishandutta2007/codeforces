namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation Increment (qs : Qubit[]) : Unit {
        let n = Length(qs);
        for (i in 1..n-1) {
            Controlled X(qs[0..n-i-1], qs[n-i]);
        }
        X(qs[0]);
    }

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        let m = 1 <<< n;
        for (i in 1..m-1) {
            Controlled H(qs[1..n-1], qs[0]);
            Increment(qs);
        }
        Increment(qs);
    }
}
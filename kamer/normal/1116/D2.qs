namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;


    operation BigHadamard(qs : Qubit[]) : Unit
    is Adj + Ctl {
        for (q in qs) {
            H(q);
        }
    }

    operation DiagonalBlocks(qs : Qubit[]) : Unit
    is Adj + Ctl {
        let N = Length(qs);
        if (N != 1) {
            Controlled BigHadamard([qs[N - 1]], qs[0..N - 2]);
            X(qs[N - 1]);
            Controlled DiagonalBlocks([qs[N - 1]], qs[0..N - 2]);
            X(qs[N - 1]);         
        }
    }

    operation Solve (qs : Qubit[]) : Unit {
        DiagonalBlocks(qs);
    }
}
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let N = Length(qs);
            if (N == 1) {
                X(qs[0]);        
            } else {
                let h = N / 2;
                Solve(qs[0..h-1]);
                for (i in 0..h-1) {
                    Controlled H([qs[i]], qs[h + i]);
                    CNOT(qs[h + i], qs[i]);
                }

            }
        }
    }
}
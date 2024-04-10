namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation RecursiveSolve (qs : Qubit[], lo : Int, hi : Int) : ()
    {
        body
        {
            if (lo+1 < hi) {
                let mid = (lo+hi) / 2;
                (Controlled H)([qs[lo]], qs[mid]);
                CNOT(qs[mid], qs[lo]);
                RecursiveSolve(qs, lo, mid);
                RecursiveSolve(qs, mid, hi);
            }
        }
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            X(qs[0]);
            RecursiveSolve(qs, 0, Length(qs));
        }
    }
}
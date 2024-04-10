namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            // your code here
            let N = Length(qs);
            mutable only0 = -1;
            mutable only1 = -1;
            for (i in 0..N - 1)
            {
                if (bits0[i] == true and bits1[i] == false)
                {
                    set only0 = i;
                }
                if (bits0[i] == false and bits1[i] == true)
                {
                    set only1 = i;
                }
            }

            for (i in 0..N - 1)
            {
                if (bits0[i] == true and bits1[i] == true)
                {
                    X(qs[i]);
                }
            }

            if (only0 != -1)
            {
                H(qs[only0]);
                for (i in 0..N - 1)
                {
                    if (bits0[i] == true and bits1[i] == false and i != only0)
                    {
                        CNOT(qs[only0], qs[i]);
                    }
                    if (bits0[i] == false and bits1[i] == true)
                    {
                        CNOT(qs[only0], qs[i]);
                        X(qs[i]);
                    }
                }
            }
            else
            {
                H(qs[only1]);
                for (i in 0..N - 1)
                {
                    if (bits0[i] == false and bits1[i] == true and i != only1)
                    {
                        CNOT(qs[only1], qs[i]);
                    }
                    if (bits0[i] == true and bits1[i] == false)
                    {
                        CNOT(qs[only1], qs[i]);
                        X(qs[i]);
                    }
                }
            }
        }
    }
}
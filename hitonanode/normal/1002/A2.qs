namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable j = -1;
            // your code here
            for (i in 0..Length(bits) - 1)
            {
                if (bits[i] == true)
                {
                    if (j == -1)
                    {
                        H(qs[i]);
                        set j = i;
                    }
                    else
                    {
                        CNOT(qs[j], qs[i]);
                    }
                }
            }
        }
    }
}
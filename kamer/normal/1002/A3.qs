namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            // first do till Hadamard
            mutable i = 0;
            mutable found = false;
            while (i < Length(qs) and not found) {
                if (bits0[i] and bits1[i]) {
                    X(qs[i]);
                }

                if (bits0[i] != bits1[i]) {
                    set found = true;
                    H(qs[i]);
                }    

                set i = i + 1;
            }

            // then do CNOTs
            mutable index = i - 1;
            while (i < Length(qs)) {
                if (bits0[i] and bits1[i]) {
                    X(qs[i]);
                }

                if (bits0[i] != bits1[i]) {
                    CNOT(qs[index], qs[i]);
                    if (bits0[i] != bits0[index]) {
                        X(qs[i]);
                    }        
                }
                
                set i = i + 1;
            }
        }
    }

}
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (i in 0..Length(qs) - 1) {
                if (bits0[i] != bits1[i]) {
                    if (M(qs[i]) == One) {
                        if (bits0[i]) {
                            return 0;
                        }
                        return 1;
                    }
                    if (bits0[i]) {
                            return 1;
                    }
                    return 0;
                }
            }
            return 0;
        }
    } 
}
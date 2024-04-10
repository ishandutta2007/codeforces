namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            using(qubit = Qubit()) {
                H(qubit);
                mutable flip = false;
                if (M(qubit) == One) {
                    Reset(qubit);
                    H(q);
                    set flip = true;
                }
                if (M(q) == One) {
                    if (flip) {
                        return 0;        
                    } else {
                        return 1;
                    }
                } else {
                    return -1;
                }

            }
        }
    }
}
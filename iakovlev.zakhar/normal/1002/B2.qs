
 namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable x = 0;
            for (i in 0..Length(qs) - 1) {
                if (M(qs[i]) == One) {
                    set x = x + 1;
                }
            }
            if (x == 1) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}
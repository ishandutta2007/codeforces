namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (i in 0..Length(qs) - 1) {
                let isOne = (M(qs[i]) == One);
                if (isOne != bits0[i]) {
                    return 1;
                } elif (isOne != bits1[i]) {
                    return 0;
                }
            }
            return 0;
        }
    }
}
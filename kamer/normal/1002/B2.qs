namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            if (Length(qs) % 2 == 1) {
                Controlled X([qs[1], qs[2]], qs[0]);
            }    

            for (i in 0..Length(qs) - 2) {
                CNOT(qs[i], qs[i + 1]);
            }

            if (M(qs[Length(qs) - 1]) == One) {
                return 1;
            } else {
                return 0;
            }

        }
    }

}
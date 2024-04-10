namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            // your code here
            mutable i = 0;
            mutable found = false;
            while (i < Length(qs) and not found) {
                if (bits[i]) {
                    H(qs[i]);
                    set found = true;
                }
                set i = i + 1;
            }

            mutable index = i - 1;

            while (i < Length(qs)) {
                if (bits[i]) {
                    CNOT(qs[index], qs[i]);
                }
                set i = i + 1;
            }
        }
    }

}
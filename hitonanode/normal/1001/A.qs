namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            // your code here
            if (sign < 0)
            {
                X(q);
            }
            H(q);
        }
    }
}
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        // your code here
        let qubitArray = inputRegister;
        let n = p % 4;
        for (i in 0..n - 1)
        {
            QFTLE(qubitArray);
        }
    }
}
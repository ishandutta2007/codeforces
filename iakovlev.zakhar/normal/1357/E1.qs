namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        if (p % 4 >= 1) {
            QFTLE(inputRegister);
        }
        if (p % 4 >= 2) {
            QFTLE(inputRegister);
        }
        if (p % 4 >= 3) {
            QFTLE(inputRegister);
        }
    }
}
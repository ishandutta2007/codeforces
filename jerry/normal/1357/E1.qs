namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        let q = (p % 4) + 4;
        for (i in 1..q) {
            QFTLE(inputRegister);
        }
    }
}
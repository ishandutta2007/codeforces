namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            if (Length(qs) == 1) {
                X(qs[0]);
            } elif (Length(qs) == 2) {
                H(qs[0]);
                CNOT(qs[0], qs[1]);
                X(qs[1]);
            } elif (Length(qs) == 4) {
                H(qs[1]);
                H(qs[2]);
                X(qs[3]);
                CCNOT(qs[1], qs[2], qs[0]);
                CNOT(qs[0], qs[1]);
                CNOT(qs[0], qs[2]);
                CNOT(qs[0], qs[3]);
                CNOT(qs[1], qs[3]);
                CNOT(qs[2], qs[3]);
            } elif (Length(qs) == 8) {
                H(qs[4]);
                H(qs[5]);
                H(qs[6]);
                X(qs[7]);
                CCNOT(qs[5], qs[6], qs[3]);
                CCNOT(qs[4], qs[6], qs[2]);
                CCNOT(qs[4], qs[5], qs[1]);
                (Controlled X)([qs[4]; qs[5]; qs[6]], qs[0]);
                CNOT(qs[0], qs[1]);
                CNOT(qs[0], qs[2]);
                CNOT(qs[0], qs[3]);
                CNOT(qs[0], qs[4]);
                CNOT(qs[0], qs[5]);
                CNOT(qs[0], qs[6]);
                CNOT(qs[0], qs[7]);
                CNOT(qs[1], qs[4]);
                CNOT(qs[1], qs[5]);
                CNOT(qs[1], qs[7]);
                CNOT(qs[2], qs[4]);
                CNOT(qs[2], qs[6]);
                CNOT(qs[2], qs[7]);
                CNOT(qs[3], qs[5]);
                CNOT(qs[3], qs[6]);
                CNOT(qs[3], qs[7]);
                CNOT(qs[4], qs[7]);
                CNOT(qs[5], qs[7]);
                CNOT(qs[6], qs[7]);
            } else {
                H(qs[11]);
                H(qs[12]);
                H(qs[13]);
                H(qs[14]);
                X(qs[15]);
                CCNOT(qs[13], qs[14], qs[10]);
                CCNOT(qs[12], qs[14], qs[9]);
                CCNOT(qs[12], qs[13], qs[8]);
                (Controlled X)([qs[12]; qs[13]; qs[14]], qs[7]);
                CCNOT(qs[11], qs[14], qs[6]);
                CCNOT(qs[11], qs[13], qs[5]);
                (Controlled X)([qs[11]; qs[13]; qs[14]], qs[4]);
                CCNOT(qs[11], qs[12], qs[3]);
                (Controlled X)([qs[11]; qs[12]; qs[14]], qs[2]);
                (Controlled X)([qs[11]; qs[12]; qs[13]], qs[1]);
                (Controlled X)([qs[11]; qs[12]; qs[13]; qs[14]], qs[0]);
                CNOT(qs[0], qs[1]);
                CNOT(qs[0], qs[2]);
                CNOT(qs[0], qs[3]);
                CNOT(qs[0], qs[4]);
                CNOT(qs[0], qs[5]);
                CNOT(qs[0], qs[6]);
                CNOT(qs[0], qs[7]);
                CNOT(qs[0], qs[8]);
                CNOT(qs[0], qs[9]);
                CNOT(qs[0], qs[10]);
                CNOT(qs[0], qs[11]);
                CNOT(qs[0], qs[12]);
                CNOT(qs[0], qs[13]);
                CNOT(qs[0], qs[14]);
                CNOT(qs[0], qs[15]);
                CNOT(qs[1], qs[3]);
                CNOT(qs[1], qs[5]);
                CNOT(qs[1], qs[8]);
                CNOT(qs[1], qs[11]);
                CNOT(qs[1], qs[12]);
                CNOT(qs[1], qs[13]);
                CNOT(qs[1], qs[15]);
                CNOT(qs[2], qs[3]);
                CNOT(qs[2], qs[6]);
                CNOT(qs[2], qs[9]);
                CNOT(qs[2], qs[11]);
                CNOT(qs[2], qs[12]);
                CNOT(qs[2], qs[14]);
                CNOT(qs[2], qs[15]);
                CNOT(qs[3], qs[11]);
                CNOT(qs[3], qs[12]);
                CNOT(qs[3], qs[15]);
                CNOT(qs[4], qs[5]);
                CNOT(qs[4], qs[6]);
                CNOT(qs[4], qs[10]);
                CNOT(qs[4], qs[11]);
                CNOT(qs[4], qs[13]);
                CNOT(qs[4], qs[14]);
                CNOT(qs[4], qs[15]);
                CNOT(qs[5], qs[11]);
                CNOT(qs[5], qs[13]);
                CNOT(qs[5], qs[15]);
                CNOT(qs[6], qs[11]);
                CNOT(qs[6], qs[14]);
                CNOT(qs[6], qs[15]);
                CNOT(qs[7], qs[8]);
                CNOT(qs[7], qs[9]);
                CNOT(qs[7], qs[10]);
                CNOT(qs[7], qs[12]);
                CNOT(qs[7], qs[13]);
                CNOT(qs[7], qs[14]);
                CNOT(qs[7], qs[15]);
                CNOT(qs[8], qs[12]);
                CNOT(qs[8], qs[13]);
                CNOT(qs[8], qs[15]);
                CNOT(qs[9], qs[12]);
                CNOT(qs[9], qs[14]);
                CNOT(qs[9], qs[15]);
                CNOT(qs[10], qs[13]);
                CNOT(qs[10], qs[14]);
                CNOT(qs[10], qs[15]);
                CNOT(qs[11], qs[15]);
                CNOT(qs[12], qs[15]);
                CNOT(qs[13], qs[15]);
                CNOT(qs[14], qs[15]);
            }
        }
    }
}
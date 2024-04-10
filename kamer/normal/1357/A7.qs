namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        using (q = Qubit[2]) {
            H(q[0]);
            H(q[1]);
            Controlled unitary([q[0]], q[1]);
            Controlled X([q[0]], q[1]);
            Controlled unitary([q[1]], q[0]);
            Controlled X([q[1]], q[0]);
            Controlled unitary([q[1]], q[0]);
            Controlled X([q[1]], q[0]);
            Controlled Z([q[0]], q[1]);
            let s = LittleEndian(q);
            QFTLE(s);
            let m0 = M(q[0]);
            let m1 = M(q[1]);
            if (m0 == Zero) {
                if (m1 == Zero) {
                    return 3;
                } else {
                    X(q[1]);
                    return 1;
                }
            } else {
                X(q[0]);
                if (m1 == Zero) {
                    return 2;
                } else {
                    X(q[1]);
                    return 0;
                }
            }
        }
    }
}
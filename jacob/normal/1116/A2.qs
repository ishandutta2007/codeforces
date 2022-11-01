namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    // open Microsoft.Quantum.Extensions.Diagnostics;

    operation Make4BitWState(x: Qubit[]) : Unit {
        body (...) {
            X(x[0]);
            using (anc = Qubit()) {
                H(anc);
                Controlled SWAP([anc], (x[0], x[1]));
                CNOT(x[1], anc);

                H(anc);
                Controlled SWAP([anc], (x[0], x[2]));
                Controlled SWAP([anc], (x[1], x[3]));
                CNOT(x[2], anc);
                CNOT(x[3], anc);
            }
            // DumpRegister((), x);
        }

        adjoint auto;
    }

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        body (...) {
            let num_options = 4;
            using (tmp = Qubit[num_options]) {
                Make4BitWState(tmp);
                // DumpMachine("machine2.txt");
                for (i in 0 .. Length(qs) - 1) {
                    for (j in 0 .. num_options - 1) {
                        if (bits[j][i]) {
                            CNOT(tmp[j], qs[i]);
                        }
                    }
                }
                // DumpMachine("machine1.txt");
                for (j in 0 .. num_options - 1) {
                    for (i in 0 .. Length(qs) - 1) {
                        if (not bits[j][i]) {
                            X(qs[i]);
                        }
                    }
                    Controlled X(qs, tmp[j]);
                    for (i in 0 .. Length(qs) - 1) {
                        if (not bits[j][i]) {
                            X(qs[i]);
                        }
                    }
                }
                // DumpMachine("machine.txt");
            }
        }

        adjoint auto;
    }
}
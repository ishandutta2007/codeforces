

    namespace Solution {
        open Microsoft.Quantum.Primitive;
        open Microsoft.Quantum.Canon;
        open Microsoft.Quantum.Math;
     
        operation CustomRz(q : Qubit) : Unit
            is Adj + Ctl {
            Rz(2.0 * PI() / 3.0, q);
            H(q);
        }
     
     
        operation B1 (qs : Qubit[]) : Int {
            CNOT(qs[0], qs[1]);
            (ControlledOnBitString([true, false], CustomRz))([qs[1], qs[2]], qs[0]);
            CNOT(qs[1], qs[2]);
            Ry(2.0 * ArcTan(Sqrt(2.0)), qs[1]);
            let b0 = M(qs[0]);
            let b1 = M(qs[1]);
            let b2 = M(qs[2]);
            if (b0 == Zero and b1 == Zero and b2 == One) {
                return 0;
            } else {
                return 1;
            }
        }
     
        operation Solve (qs : Qubit[]) : Int {
            // your code here
            return B1(qs);
        }
    }
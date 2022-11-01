namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable bestQty = 0;
        mutable bestAng = PI();
        mutable curAng = 0.0;
        for (i in 1..100) {
            set curAng += theta;
            if (curAng >= 2.0*PI()) {
                set curAng -= 2.0*PI();
            }
            mutable myAng = AbsD(PI() - curAng);
            if (myAng < bestAng) {
                set bestQty = i;
                set bestAng = myAng;
            }
        }

        using (q = Qubit()) {
            for (i in 1..bestQty) {
                unitary(q);
            }
            if (M(q) == Zero) {
                return 0;
            } else {
                X(q);
                return 1;
            }
        }
    }
}
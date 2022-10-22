namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable theta0 = theta / 2.0;
        mutable reps = 1;
        mutable thetaSum = theta0;
        if (thetaSum < PI() / 4.0) {
            repeat {
                set thetaSum += theta0;
                set reps = reps + 1;
            } until (thetaSum > PI() / 4.0);
        }
        
        using (q = Qubit()) {
            for (i in 0..20) {
                for (j in 0..reps-1) {
                    unitary(q);
                }
                if (M(q) == One) {
                    X(q);
                    return 1;
                }
            }
        }
        return 0;
    }
}
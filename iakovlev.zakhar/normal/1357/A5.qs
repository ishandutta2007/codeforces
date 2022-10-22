namespace Solution {
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable pi = 3.141592654;
        mutable ans = 0;
        mutable p = 0;
        mutable angle = theta / pi;
        if (angle > 0.5) {
            set angle = 1.0 - angle;
        }
        if (angle < 0.025) {
            set p = 25;
        } elif (angle < 0.075) {
            set p = 9;
        } elif (angle < 0.18) {
            set p = 3;
        } elif (angle < 0.25) {
            set p = 1;
        }
        using (x = Qubit[1]) {
            for (i in 0..30) {
                for (j in 0..p) {
                    unitary(x[0]);
                }
                if (M(x[0]) == One) {
                    set ans = 1;
                }
                Reset(x[0]);
            }
        }
        return ans;
    }
}
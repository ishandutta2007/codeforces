namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    operation Solve(t : Double, u : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            for (i in 0 .. 30) { 
                u(q);
                mutable s = t;
                repeat {} until (AbsD(Sin(s / 2.)) > Sqrt(0.5)) fixup {
                    u(q);
                    set s += t;
                }
                let r = M(q);
                Reset(q);
                if (r == One) {
                    return 1;
                }
            }
        }
        return 0;
    }
}
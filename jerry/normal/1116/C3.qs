namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    
    operation increment(ans : Qubit[]) : Unit {
        body {
            CNOT(ans[1], ans[0]);
            X(ans[0]);
            CNOT(ans[0], ans[1]);
            X(ans[0]);
        }
        controlled auto;
    }

    operation CountZeroes(x : Qubit[], ans: Qubit[]) : Unit {
        mutable n = Length(x);
        for (i in 0..n-1) {
            Controlled increment([x[i]], ans);
        }
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body {
            using (ans = Qubit[2]) {
                CountZeroes(x, ans);
                ApplyToEach(X, ans);
                Controlled X(ans, y);
                ApplyToEach(X, ans);
                CountZeroes(x, ans);
                CountZeroes(x, ans);
            }
        }
        adjoint self;
    }
}
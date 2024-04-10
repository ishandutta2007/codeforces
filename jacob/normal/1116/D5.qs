namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation IsSame(l: Qubit, r: Qubit, output: Qubit) : Unit {
        body (...) {
            CCNOT(l, r, output);
            X(l);
            X(r);
            CCNOT(l, r, output);
            X(l);
            X(r);
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
        using (anc = Qubit()) {
            IsSame(qs[1], qs[2], anc);
            Controlled H([anc], qs[0]);
            Controlled X([anc, qs[0]], qs[1]);
            Controlled X([anc, qs[0]], qs[2]);
            Controlled H([anc], qs[0]);
            X(anc);
            //Controlled SWAP([anc], (qs[1], qs[2]));
            Controlled X([anc], qs[0]);
            Controlled X([anc, qs[0]], qs[1]);
            Controlled X([anc, qs[0]], qs[2]);
            Controlled H([anc], qs[0]);
            X(anc);
            IsSame(qs[1], qs[2], anc);
        }
    }

    operation SingleArgumentSolve(x: Qubit[]) : Unit {
        body (...) {
            Solve(x);
        }
    }
}
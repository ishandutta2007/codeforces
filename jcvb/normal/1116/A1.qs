namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;
 
 
    operation Solve (qs : Qubit[]) : Unit {
		using (r = Qubit() ){
			repeat {
				ResetAll(qs);
				H(qs[0]);
				H(qs[1]);
				Controlled X(qs, r);
			} until (M(r)==Zero );

			Reset(r);
		}
        // your code here
    }
 
 
}
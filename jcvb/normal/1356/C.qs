namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;
 
 
    operation Solve (qs : Qubit[]) : Unit {
		using (r = Qubit() ){
			repeat {
			    Reset(r);
				ResetAll(qs);
				H(qs[0]);
				H(qs[1]);
				Controlled X(qs, r);
			} until (M(r)==Zero );
			X(qs[0]);
			X(qs[1]);
			
		}
        // your code here
    }
 
 
}
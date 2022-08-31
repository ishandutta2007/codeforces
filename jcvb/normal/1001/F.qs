namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
		mutable ans = 0;
		let n = Length(qs);
		for (i in 0..n-1) {
			if ((M(qs[i]) == Zero) and  (bits0[i]==true)) {
				set ans = 1;
			}
			if ((M(qs[i]) == One) and  (bits0[i]==false)) {
				set ans = 1;
			}
		}
		return ans;
    }

	
}
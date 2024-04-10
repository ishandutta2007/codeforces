namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (q: Qubit) : Int {
		mutable r=0;
		using (g = Qubit()) {
			H(g);
			if (M(g)==One) {
				set r = 1;
			}
			Reset(g);
		}
		if( r==0) {
			if(M(q)== One) {
				return 1;
			} else {
				return -1;
			}
		}else {
			Ry(PI()/2.0,q);
			if (M(q)==Zero) {
				return 0;
			}else {
				return -1;
			}
		}
	}

}
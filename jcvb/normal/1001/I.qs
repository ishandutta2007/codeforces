namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
		mutable ret = true;
		using ((qs,q) = (Qubit[N],Qubit())) {
			X(q);
			H(q);
			for (qi in qs) {
				H(qi);
			}
			
			Uf(qs,q);
			
			for (qi in qs) {
				H(qi);
			}
		
			for (qi in qs) {
				if (M(qi) != Zero) {
					set ret = false;
				}
			}
			ResetAll (qs);
			Reset(q);
		}
		return ret;
	}


}
namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
		mutable res=0;
		using ((qs,q) = (Qubit[N],Qubit())) {
			Uf(qs,q);
			if (M(q)==One) {
				set res=1;
			}
			ResetAll(qs);
			Reset(q);
		}
		mutable a = new Int[N];
		for (j in 0..N-1) {
			set a w/= j <- 1;
		}
		if(res==1) {
			set a w/= 0 <- 0;
		}
		return a;
	}


}
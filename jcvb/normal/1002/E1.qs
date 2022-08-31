namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
		mutable a = new Int[N];
		using ((qs,q) = (Qubit[N],Qubit())) {
			X(q);
			H(q);
			for (qq in qs) {
				H(qq);
			}
			Uf(qs,q);
			for (qq in qs) {
				H(qq);
			}
			for (i in 0..N-1)  {
				if(M(qs[i])==One) {
					set a w/= i <- 1;
				} else {
					set a w/= i <- 0;
				}

			}


			ResetAll(qs);
			Reset(q);
		}
		return a;
	}


}
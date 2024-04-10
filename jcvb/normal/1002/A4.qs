namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Diagnostics;


	operation Solve (qs: Qubit[]) : Unit {
		let n = Length(qs);

		mutable m=0;
		for (i in 0..4) {
			if ((1 <<< i) == n) {
				set m = i;
			}
		}
		using (qq = Qubit[m]) {
			for (qqq in qq ) {
				H(qqq);
			}
			for (i in 0..n-1) {
				for (j in 0..m-1) {
					if (((1<<<j) &&& i) == 0) {
						X(qq[j]);
					}
				}
				Controlled X(qq,qs[i]);
				for (j in 0..m-1) {
					if (((1<<<j) &&& i) == 0) {
						X(qq[j]);
					}
				}
			}

			//DumpMachine();
			for (i in 0..n-1) {
				for (j in 0..m-1) {
					if (((1<<<j) &&& i) != 0) {
						CNOT(qs[i],qq[j]);
					}
				}

			}
			//ResetAll(qq);
			//DumpMachine();
		}
	}


}
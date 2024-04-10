namespace Solution {
	open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Measurement;
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Diagnostics;
	open Microsoft.Quantum.Convert;
 
   operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = IntAsBoolArray(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine();
                
                ResetAll(qs);
            }
        }
    }
 
	operation Solve (x: Qubit[]) : Unit is Adj+Ctl {
		let n = Length(x);
		for (i in 0..(1<<<(n-1))-1) {
			for (j in 0..n-2) {
				CNOT(x[n-1],x[j]);
			}

			for (j in 0..n-2) {
				if (((i>>>j)&&& 1)!=1) {
					X(x[j]);
				}
			}
			Controlled H(x[0..n-2],x[n-1]);
			for (j in 0..n-2) {
				if (((i>>>j)&&& 1)!=1) {
					X(x[j]);
				}
			}

			for (j in 0..n-2) {
				CNOT(x[n-1],x[j]);
			}
		}
	}
	
 
 
}
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
 
 operation Jia (x: Qubit[]) : Unit is Adj+Ctl {
		CNOT(x[0],x[1]);
		X(x[0]);
		using (qq=Qubit() ) {
			Controlled X(x,qq);
			CNOT(qq,x[0]);
			CNOT(qq,x[1]);
			(ControlledOnInt(0,X))(x,qq);
		}
	}

	operation cha (q: Qubit): Unit is Adj+Ctl {
		Rz(PI()*0.1,q);
	}
 
 operation Increment (register : LittleEndian) : Unit is Adj+Ctl {
        // your code here
		let n = Length(register!);
		for (i in n-1..-1..0) {
			Controlled X(register![0..i-1],register![i]);
		}
 
    }

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
		using (qs = Qubit[2]) {
			H(qs[0]);
			H(qs[1]);
			Controlled QFTLE([qs[0]], inputRegister);
			Controlled QFTLE([qs[1]], inputRegister);
			Controlled QFTLE([qs[1]], inputRegister);
			SWAP(qs[0],qs[1]);
			H(qs[0]);
			Controlled Adjoint S([qs[0]],qs[1]);
			H(qs[1]);

			R1(PI()/2.0/IntAsDouble(p), qs[0]);
			R1(PI()/IntAsDouble(p), qs[1]);

			H(qs[1]);
			Controlled S([qs[0]],qs[1]);
			H(qs[0]);
			SWAP(qs[0],qs[1]);
			Adjoint Controlled QFTLE([qs[1]], inputRegister);
			Adjoint Controlled QFTLE([qs[1]], inputRegister);
			Adjoint Controlled QFTLE([qs[0]], inputRegister);
			H(qs[1]);
			H(qs[0]);
		}
    }

 
 
}
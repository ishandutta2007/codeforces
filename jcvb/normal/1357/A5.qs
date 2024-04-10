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
 
	operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable ret = 0;
		mutable done = 0;

		mutable tims = 1;
		if (theta < 0.15 * PI()) {
			set tims = Round((0.3* PI())/ theta);
		} elif (theta > 0.85*PI()) {
			set tims = Round((0.3* PI())/ (PI()-theta));
		}
		using (r = Qubit()) {
			repeat{
				Reset(r);
				Ry(-theta*IntAsDouble(tims), r);
				for (j in 0..tims-1) {
					unitary(r);
				}
				if (M(r)== One) {
					set done=1;
					set ret = 0;
				}
				Reset(r);

				H(r);
				Rz(-theta*IntAsDouble(tims),r);
				for (j in 0..tims-1) {
					unitary(r);
				}
				H(r);
				if (M(r)==One) {
					set done = 1;
					set ret = 1;
				}
			} until (done == 1);
			Reset(r);
		}
		return ret;
	}

 
}
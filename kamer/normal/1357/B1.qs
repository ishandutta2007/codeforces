    namespace Solution {
        open Microsoft.Quantum.Intrinsic;
        open Microsoft.Quantum.Canon;
     
        operation PlusOne(qs : Qubit[]) : Unit
        is Ctl + Adj {
            X(qs[0]);
            for (i in 0..Length(qs)-2) {
                ApplyToEachCA(X, qs[0..i]);
                Controlled X(qs[0..i], qs[i + 1]);
                ApplyToEachCA(X, qs[0..i]);
            }
        }
        
        operation MinusOne(qs : Qubit[]) : Unit
        is Ctl + Adj {
            X(qs[0]);
            for (i in 0..Length(qs)-2) {
                Controlled X(qs[0..i], qs[i + 1]);
            }
        }
        
        operation FillCounters(qs : Qubit[], counter : Qubit[]) : Unit
        is Ctl + Adj {
            for (q in qs) {
                Controlled PlusOne([q], counter);
            }
        }
        
        operation DeFillCounters(qs : Qubit[], counter : Qubit[]) : Unit
        is Ctl + Adj {
            for (q in qs) {
                Controlled MinusOne([q], counter);
            }
        }
        
        operation CheckEqual(counter : Qubit[], y : Qubit, target : Int) : Unit
        is Ctl + Adj {
            (ControlledOnInt(target, X))(counter, y);
        }
        
        operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
            // your code here
            using ((counter) = (Qubit[3])) {
                FillCounters(inputs, counter);
                CheckEqual(counter, output, Length(inputs) / 2);
                DeFillCounters(inputs, counter);
            }
        }
    }
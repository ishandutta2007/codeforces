    namespace Solution {
        open Microsoft.Quantum.MachineLearning;
     
        operation Solve () : (ControlledRotation[], (Double[], Double)) {
            // your code here
            let cr = [
                ControlledRotation((0, new Int[0]), PauliY, 0)
            ];
            return (cr, ([1.0], 0.25880000000000003));
        }
    }
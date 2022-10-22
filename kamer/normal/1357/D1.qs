    namespace Solution {
        open Microsoft.Quantum.MachineLearning;
     
        operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
            // your code here
            let mode = (4, [1.0, 1.0]);
            let rotations = [
                ControlledRotation((0, new Int[0]), PauliX, 4),
                ControlledRotation((0, new Int[0]), PauliZ, 5),
                ControlledRotation((1, new Int[0]), PauliX, 6),
                ControlledRotation((1, new Int[0]), PauliZ, 7),
                ControlledRotation((0, [1]), PauliX, 0),
                ControlledRotation((0, [1]), PauliZ, 8),
                ControlledRotation((1, [0]), PauliX, 1),
                ControlledRotation((1, [0]), PauliZ, 9),
                ControlledRotation((1, new Int[0]), PauliZ, 2),
                ControlledRotation((1, new Int[0]), PauliX, 3)
            ];
            let paramsss = ([0.060057, 3.00522, 2.03083, 0.63527, 1.03771, 1.27881, 4.10186, 5.34396, 2.74312, 4.20734], -0.06045);
            return (mode, rotations, paramsss);
        }
    }
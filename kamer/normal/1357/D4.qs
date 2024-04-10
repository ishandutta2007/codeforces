namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        // your code here
        let mode = (1, [1.0, 1.0]);
        let rotations = [
            ControlledRotation((0, new Int[0]), PauliX, 4),
            ControlledRotation((0, new Int[0]), PauliZ, 5),
            ControlledRotation((1, new Int[0]), PauliX, 6),
            ControlledRotation((1, new Int[0]), PauliZ, 7),
            ControlledRotation((0, [1]), PauliX, 0),
            // ControlledRotation((0, [1]), PauliZ, 8),
            ControlledRotation((1, [0]), PauliX, 1),
            ControlledRotation((0, [1]), PauliX, 8),
            // ControlledRotation((1, [0]), PauliZ, 9),
            ControlledRotation((1, new Int[0]), PauliZ, 2),
            ControlledRotation((1, new Int[0]), PauliX, 3)
        ];
        let paramss = ([3.1415, 3.1415, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1415], -0.020399999999999974);
        return (mode, rotations, paramss);
    }
}
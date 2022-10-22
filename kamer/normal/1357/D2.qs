namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        let mode = (4, [10.0, 0.1]);
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
        let paramss = ([3.1415, 3.1415, 0.024500000000000077, 0.024500000000000077, 0.024500000000000077, 0.024500000000000077, 0.024500000000000077, 0.024500000000000077, 3.1415], -0.48210000000000003);
        return (mode, rotations, paramss);
    }
}
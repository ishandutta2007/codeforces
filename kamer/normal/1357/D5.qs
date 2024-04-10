    namespace Solution {
        open Microsoft.Quantum.MachineLearning;
     
        operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
            // your code here
            let mode = (1, [1.0]);
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
            let paramss = ([0.5864553485999999, 3.4393926223, -0.5296231500796885, 1.5798674738203116, -0.24993299317968853, 1.6287305668203116, 0.8466910958203113, 4.305075127820311, 4.716075315], 0.20183637853950132);
            return (mode, rotations, paramss);
        }
    }
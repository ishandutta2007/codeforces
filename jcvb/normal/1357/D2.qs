// This file is submitted by the participant
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    // The operation that the participant has to implement
    // Has to return three things: 
    //  1) the feature engineering to perform (as an index in the array of feature engineering functions and an array of parameters to be used with it)
    //  2) circuit structure (as an array of ControlledRotation)
    //  3) and training results (circuit parameters + bias)
    //
    // The features engineering is built-in and cannot be tweaked by the participant's solution, only chosen from the list 
    // (see quantum-checker.qs for the list of available feature engineering functions)
    //
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((4, [10.0,1.0]), 
                [
	ControlledRotation((0, new Int[0]), PauliX, 4),
	ControlledRotation((0, new Int[0]), PauliZ, 5),
	ControlledRotation((1, new Int[0]), PauliX, 6),
	ControlledRotation((0, [1]), PauliX, 0),
	ControlledRotation((0, [1]), PauliZ, 7),
	ControlledRotation((1, [0]), PauliX, 1),
	ControlledRotation((1, new Int[0]), PauliZ, 2),
	ControlledRotation((1, new Int[0]), PauliX, 3),
    ],
    ([1.567,4.333,4.864,0.9950570000000001,1.20522,2.5858299999999996,7.07027,2.93771],0.18622982290370205));
    }


}
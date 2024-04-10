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
        return ((1, [0.4,0.4]), 
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
                 ([0.860057,1.20522,2.6658299999999953,1.1502699999999955,5.132709999999996,0.3538099999999954,5.316859999999996,6.24396], -0.2883005434835026));
    }


}
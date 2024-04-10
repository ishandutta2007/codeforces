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
        return ((4, [1.0,1.0]), 
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
     ([2.3347582301853995,2.110614376145884,4.93567055138914,4.56054056612468,8.81766615797912,6.0855701256705705,6.968056507779406,2.9656038531290405],0.11404572953135733));
    //([1.867,2.333,7.886849999999998,1.7215070000000017,3.5161600000000006,3.0148200000000003,7.0785100000000005,2.93771], 0.08751863947681988));
     //([1.867,2.333,7.886849999999998,1.7215070000000017,3.5161600000000006,3.0148200000000003,7.0785100000000005,2.93771], 0.09684319822399473));
    //([1.867,2.333,7.886849999999998,1.7215070000000017,3.5161600000000006,3.0148200000000003,7.0785100000000005,2.93771], 0.09738319822399472));
     //([1.867,2.333,7.886849999999997,1.721507000000001,3.47892,2.9775799999999997,7.04127,2.93771], 0.09086897697254648));
     	//([1.567,2.333,7.998999999999999,1.8600570000000003,3.4257200000000005,2.89183,6.935270000000001,2.93771],0.10019808596944002));
    }


}
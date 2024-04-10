#include "bits/stdc++.h"
using namespace std;

long long D, K, A, B, T, driven, walked, reps, sol;

int main(){
	cin >> D >> K >> A >> B >> T;
	if (A*K - B*K + T >= 0){
		reps = 0;
	} else {
		reps = D/K - 1;
	}
	if (D > K){
		sol = B*D + A*K - B*K + reps * (A*K - B*K + T);
	} else {
		sol = A*D;
	}
	sol = min(sol, A*D + T*((D-1)/K));
	cout << sol;
	//cin >> D;
	return 0;
}
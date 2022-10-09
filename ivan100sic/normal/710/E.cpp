#include "bits/stdc++.h"
using namespace std;

long long D[10000005];
long long L, X, Y;

int main(){
	cin >> L >> X >> Y;
	
	D[0] = 0;
	for (int i=1; i<=L; i++){
		if (i % 4 == 3){
			D[i] = min(D[i-1] + X, D[(i+1)/4] + X + Y + Y);
		} else if (i % 4 == 1){
			D[i] = D[i-1] + X;
		} else {
			D[i] = min(D[i-1] + X, D[i/2] + Y);
		}
	}
	
	cout << D[L];
	
	return 0;
}
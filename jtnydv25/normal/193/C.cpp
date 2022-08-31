#include <bits/stdc++.h>
using namespace std;

int main(){
	int p, q, r, f12, f13, f23;
	cin >> p >> q >> r >> f12>> f13 >> f23;
	int a1 = p, a2 = q, a3 = r;
	// a1 + a2 - 2 * t1 = s
	if(a1 + a2 < f12|| ((a1 + a2 - f12) & 1)){
		cout << -1;
		return 0;
	}
	int t1 = (a1 + a2 - f12) / 2;

	if(a1 + a3 < f13 || ((a1 + a3 - f13) & 1)){
		cout << -1;
		return 0;
	}

	int t2 = (a1 + a3 - f13) >> 1;

	if(a2 + a3 < f23 || ((a2 + a3 - f23) & 1)){
		cout << -1;
		return 0;
	}
	
	int t3 = (a2 + a3 - f23) >> 1;
	int only1 = a1 - t1, only2 = a2 - t1, both = t1;

	int len = both + only1 + only2;

	// x1 <= both
	// x2 <= only1
	// x3 <= only2
	// x1 + x2 + x3 + x4 = a3
	// x1 + x2 = t2
	// x1 + x3 = t3

	if(both + only1 < t2 || both + only2 < t3){
		cout << -1;
		return 0;
	}
	int X4 = 1e9;
	int X1 = 0, X2 = 0, X3 = 0;
	for(int x1 = 0; x1 <= both; x1++){
		int x2 = t2 - x1;
		int x3 = t3 - x1;
		if(x2 >= 0 && x2 <= only1 && x3 >= 0 && x3 <= only2){
			int x4 = a3 - x1 - x2 - x3;
			if(x4 >= 0){
				if(x4 < X4){
					X4 = x4;
					X1 = x1, X2 = x2, X3 = x3;
				}
			}
		}
	}
	if(X4 > 1e6){
		cout << -1;
		return 0;
	}

	int minL = both + only1 + only2 + X4;
	string A, B, C, D;
	for(int j = 0; j < minL; j++){
		A += "b";
		B += (j < a1) ? "a" : "b";
		C += (j < t1 || (j >= a1 && j < len)) ? "a" : "b";
		D += (j < X1 || j >= both && j < both + X2 || j >= a1 && j < a1 + X3 || j >= len) ? "a" : "b";
	}
	cout << minL << endl;
	cout << A << endl << B << endl << C << endl << D ;
}
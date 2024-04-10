#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

#define ll long long

ll a[3][2], x[3], y[3], p[6][3] = {1, 2, 3};
char c1, c2, c3;

int main(){
	
	for(ll i = 0; i < 3; i++){
		cin >> a[i][0] >> a[i][1];
		for(ll j = 0; j < 6; j++){
			p[j][i] = i;
		}
	}
	
	for(ll i = 0; i < 6; i++){
		for(ll j = 0; j < i; j++){
			next_permutation(p[i], p[i] + 3);
		}
	}
	
	for(ll i = 0; i < 6; i++){
		for(ll j = 0; j < 3; j++){
			x[j] = a[p[i][j]][0];
			y[j] = a[p[i][j]][1];
		}
		for(ll r1 = 0; r1 < 2; r1++){
			swap(x[0], y[0]);
			for(ll r2 = 0; r2 < 2; r2++){
				swap(x[1], y[1]);
				for(ll r3 = 0; r3 < 2; r3++){
					swap(x[2], y[2]);
					if(x[0] + x[1] == x[2] && y[0] == y[1] && y[0] + y[2] == x[2]){
						c1 = 'A' + p[i][0];
						c2 = 'A' + p[i][1];
						c3 = 'A' + p[i][2];
						cout << x[2] << endl;
						for(ll i = 0; i < y[2]; i++){
							for(ll j = 0; j < x[2]; j++){
								cout << c3;
							}
							cout << endl;
						}
						for(ll i = 0; i < y[0]; i++){
							for(ll j = 0; j < x[0]; j++){
								cout << c1;
							}
							for(ll j = 0; j < x[1]; j++){
								cout << c2;
							}
							cout << endl;
						}
						return 0;
					}
					if(x[0] == x[1] && x[1] == x[2] && y[0] + y[1] + y[2] == x[0]){
						c1 = 'A' + p[i][0];
						c2 = 'A' + p[i][1];
						c3 = 'A' + p[i][2];
						cout << x[2] << endl;
						for(ll i = 0; i < y[2]; i++){
							for(ll j = 0; j < x[2]; j++){
								cout << c3;
							}
							cout << endl;
						}
						for(ll i = 0; i < y[1]; i++){
							for(ll j = 0; j < x[1]; j++){
								cout << c2;
							}
							cout << endl;
						}
						for(ll i = 0; i < y[0]; i++){
							for(ll j = 0; j < x[0]; j++){
								cout << c1;
							}
							cout << endl;
						}
						return 0;
					}
				}
			}
		}
	}
	
	
	
	cout << -1;
	return 0;
}
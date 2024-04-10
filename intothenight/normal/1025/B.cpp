#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
		}
	}
	vector<int> primes;
	for(auto x: a[0]){
		for(auto p = 2; p * p <= x; ++ p){
			if(x % p == 0){
				primes.push_back(p);
				while(x % p == 0){
					x /= p;
				}
			}
		}
		if(x > 1){
			primes.push_back(x);
		}
	}
	for(auto p: primes){
		for(auto i = 1; i < n; ++ i){
			if(a[i][0] % p && a[i][1] % p){
				goto FAIL;
			}
		}
		cout << p << "\n";
		return 0;
		FAIL:;
	}
	cout << "-1\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, p;
	cin >> n >> p;
	vector<array<int, 2>> a(n);
	long long tot = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
		tot += a[i][0];
	}
	if(tot <= p){
		cout << "-1\n";
		return 0;
	}
	long double low = 0, high = 1e25;
	for(auto rep = 0; rep < 300; ++ rep){
		long double mid = (low + high) / 2, rem = p;
		bool ok = true;
		for(auto &[s, cur]: a){
			if(cur >= mid * s){
				continue;
			}
			if((long double) s * mid > rem * mid + cur){
				ok = false;
				break;
			}
			rem -= s - (long double) cur / mid;
		}
		(ok ? low : high) = mid;
	}
	cout << fixed << setprecision(15) << low << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
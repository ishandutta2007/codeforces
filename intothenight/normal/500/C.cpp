#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> w(n);
	for(auto i = 0; i < n; ++ i){
		cin >> w[i];
	}
	vector<int> lp(n, -1), a(m);
	int res = 0;
	for(auto i = 0; i < m; ++ i){
		cin >> a[i], -- a[i];
		vector<int> added(n);
		for(auto t = lp[a[i]] + 1; t < i; ++ t){
			if(!added[a[t]]){
				added[a[t]] = true;
				res += w[a[t]];
			}
		}
		lp[a[i]] = i;
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	using bs = bitset<2000>;
	vector<bs> adjm(n), radjm(n);
	int r = -1;
	for(auto u = 0; u < n; ++ u){
		for(auto v = 0; v < n; ++ v){
			int x;
			cin >> x;
			if(x){
				adjm[u][v] = radjm[v][u] = true;
				if(u == v){
					r = u;
				}
			}
		}
	}
	bs dp, rdp;
	dp[r] = rdp[r] = true;
	for(auto rep = 0; rep < n; ++ rep){
		bs dp_next, rdp_next;
		for(auto v = dp._Find_first(); v < n; v = dp._Find_next(v)){
			dp_next |= adjm[v];
		}
		for(auto v = rdp._Find_first(); v < n; v = rdp._Find_next(v)){
			rdp_next |= radjm[v];
		}
		if(dp == dp_next && rdp == rdp_next){
			break;
		}
		swap(dp, dp_next), swap(rdp, rdp_next);
	}
	if(dp.count() != n || rdp.count() != n){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
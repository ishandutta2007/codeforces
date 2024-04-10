#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	vector<int> vis(n);
	int res = 1;
	for(auto u = 0; u < n; ++ u){
		if(!vis[u]){
			int v = u, sz = 0;
			while(!vis[v]){
				vis[v] = true;
				v = a[v];
				++ sz;
			}
			if(u == v){
				res = lcm(res, sz % 2 ? sz : sz / 2);
			}
			else{
				cout << "-1\n";
				return 0;
			}
		}
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
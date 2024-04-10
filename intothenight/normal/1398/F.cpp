#include "bits/stdc++.h"
using namespace std;



struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); }
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		p[u] += p[v], p[v] = u;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	vector<array<int, 2>> dp(n + 1);
	vector<int> reach(n);
	for(auto i = n - 1; i >= 0; -- i){
		if(s[i] != '1'){
			dp[i][0] = dp[i + 1][0] + 1;
		}
		if(s[i] != '0'){
			dp[i][1] = dp[i + 1][1] + 1;
		}
		reach[i] = max(dp[i][0], dp[i][1]);
	}
	disjoint_set dsu(n + 1);
	for(auto l = 1; l <= n; ++ l){
		int res = 0;
		for(auto i = 0; i < n; ){
			if(reach[i] < l){
				dsu.merge(i + 1, i);
				i = dsu.root(i);
			}
			else{
				res += reach[i] / l;
				i += reach[i] / l * l;
			}
		}
		cout << res << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
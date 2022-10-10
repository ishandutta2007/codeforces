#include <bits/stdc++.h>
using namespace std;

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	disjoint_set dsu(n);
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		for(auto j = 0; j < n; ++ j){
			if(s[j] == '1'){
				dsu.merge(i, j);
			}
		}
	}
	vector<vector<int>> grp(n), val(n);
	for(auto i = 0; i < n; ++ i){
		grp[dsu.root(i)].push_back(i);
		val[dsu.root(i)].push_back(a[i]);
	}
	vector<int> res(n, -1);
	for(auto i = 0; i < n; ++ i){
		sort(val[i].begin(), val[i].end());
		for(auto t = 0; t < (int)val[i].size(); ++ t){
			res[grp[i][t]] = val[i][t];
		}
	}
	for(auto x: res){
		cout << x +1 << " ";
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
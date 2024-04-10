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
		p[u] += p[v], p[v] = u;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> next(n, -1), f(n), fixed;
	disjoint_set dsu(n);
	for(auto i = 0; i < n; ++ i){
		cin >> f[i], -- f[i];
		if(i != f[i]){
			if(!dsu.merge(f[i], i)){
				cout << "-1\n";
				return 0;
			}
			next[i] = f[i];
		}
		else{
			fixed.push_back(i);
		}
	}
	for(auto i = 0; i < n; ++ i){
		if(~next[i]){
			if(~next[next[i]]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	int m = (int)fixed.size();
	vector<int> pos(n);
	for(auto i = 0; i < m; ++ i){
		pos[fixed[i]] = i;
	}
	cout << m << "\n";
	for(auto i = 0; i < n; ++ i){
		cout << pos[dsu.root(i)] + 1 << " ";
	}
	cout << "\n";
	for(auto i = 0; i < m; ++ i){
		cout << fixed[i] + 1 << " ";
	}
	cout << "\n";
	return 0;
}

/*
g: surjective
h: injective
m <= n
f(h(x)) = h(x)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
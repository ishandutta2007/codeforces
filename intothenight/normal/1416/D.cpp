#include <bits/stdc++.h>
using namespace std;



struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){}
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	int sz(int u){
		return -p[root(u)];
	}
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		p[u] += p[v], p[v] = u;
		return true;
	}
};

struct segment_tree{
	segment_tree(vector<array<int, 2>> a): n((int)a.size()), val(n << 1){
		copy(a.begin(), a.end(), val.begin() + n);
		for(auto i = n - 1; i > 0; -- i){
			val[i] = max(val[i << 1], val[i << 1 | 1]);
		}
	}
	void update(int p){
		for(val[p += n][0] = 0; p >>= 1; ){
			val[p] = max(val[p << 1], val[p << 1 | 1]);
		}
	}
	array<int, 2> query(int l, int r){
		array<int, 2> res = {-1, -1};
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, val[l ++]);
			if(r & 1) res = max(res, val[-- r]);
		}
		return res;
	}
	int n;
	vector<array<int, 2>> val;
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<array<int, 2>> edges(m);
	for(auto &[u, v]: edges){
		cin >> u >> v, -- u, -- v;
	}
	vector<array<int, 2>> query(qn);
	vector<int> eflag(m);
	for(auto &[type, q]: query){
		cin >> type >> q, -- q;
		if(type == 2){
			eflag[q] = true;
		}
	}
	vector<list<int>> L(n);
	for(auto u = 0; u < n; ++ u){
		L[u].push_back(u);
	}
	disjoint_set dsu(n);
	for(auto i = 0; i < m; ++ i){
		if(!eflag[i]){
			auto [u, v] = edges[i];
			u = dsu.root(u), v = dsu.root(v);
			if(dsu.merge(u, v)){
				L[u].splice(L[u].end(), L[v]);
			}
		}
	}
	vector<int> qfrom;
	vector<int> qlen;
	for(auto i = qn - 1; i >= 0; -- i){
		auto [type, q] = query[i];
		if(type == 1){
			qfrom.push_back(dsu.root(q));
			qlen.push_back(dsu.sz(q));
		}
		else{
			auto [u, v] = edges[q];
			u = dsu.root(u), v = dsu.root(v);
			if(dsu.merge(u, v)){
				L[u].splice(L[u].end(), L[v]);
			}
		}
	}
	reverse(qfrom.begin(), qfrom.end());
	reverse(qlen.begin(), qlen.end());
	list<int> T;
	for(auto &l: L){
		T.splice(T.end(), l);
	}
	vector<array<int, 2>> val;
	vector<int> pos(n);
	for(auto u: T){
		pos[u] = (int)val.size();
		val.push_back({a[u], pos[u]});
	}
	segment_tree tr(val);
	for(auto i = 0; i < (int)qfrom.size(); ++ i){
		auto [x, p] = tr.query(pos[qfrom[i]], pos[qfrom[i]] + qlen[i]);
		cout << x << "\n";
		tr.update(p);
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
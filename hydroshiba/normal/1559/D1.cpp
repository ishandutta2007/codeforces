#include "bits/stdc++.h"
using namespace std;

struct dsu{
	int n;
	vector<int> par;
	set<int> s;

	dsu(int _n){
		n = _n;
		par.resize(n + 1);
		iota(par.begin(), par.end(), 0);
		for(int i = 1; i <= n; ++i) s.insert(i);
	}

	int root(int a){
		while(a != par[a]){
			par[a] = par[par[a]];
			a = par[a];
		}

		return a;
	}

	bool same(int a, int b){
		a = root(a);
		b = root(b);

		return (a == b);
	}

	void join(int a, int b){
		a = root(a);
		b = root(b);

		s.erase(a);
		par[a] = b;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m1, m2;
	cin >> n >> m1 >> m2;

 	dsu g1(n), g2(n);
	while(m1--){
		int u, v;
		cin >> u >> v;
		g1.join(u, v);
	}

	while(m2--){
		int u, v;
		cin >> u >> v;
		g2.join(u, v);
	}

	int ans = 0;
	queue<int> q;

	while(g1.s.size() != 1 && g2.s.size() != 1){
		for(int u = 1; u <= n; ++u) 
		for(int v = 1; v <= n; ++v) if(u != v && !g1.same(u, v) && !g2.same(u, v)){
			q.push(u);
			q.push(v);
			g1.join(u, v);
			g2.join(u, v);
			++ans;
			break;
		}
	}

	cout << ans << '\n';
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
		cout << q.front() << '\n';
		q.pop();
	}
}
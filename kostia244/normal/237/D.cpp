#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
int n, cnt = 0;
vector<vi> g;
vector<pair<int, int>> vs, e;
void dfs(int v, int p, int P) {
	int q = -1;
	for(auto i : g[v]) {
		if(i == p) continue;
		vs.pb({v, i});
		if(P!=-1)
		e.pb({P, vs.size()});
		if(v==1) {
			if(q!=-1)e.pb({q, vs.size()});
			q = vs.size();
		}
		dfs(i, v, vs.size());
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	dfs(1, 1, -1);
	cout << n-1 << "\n";
	for(auto i : vs) cout << "2 " << i.first << " " << i.second << "\n";
	for(auto i : e) cout << i.first << " " << i.second << "\n";
}
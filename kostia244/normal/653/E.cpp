#include<bits/stdc++.h>
using namespace std;
const int N = 300300;
int n, m, k, mindeg = 0, maxdeg, comps = 0;
set<int> g[N];
vector<int> q;
void dfs(int v) {
	vector<int> qq, go;
	for(auto i : q) {
		assert(i);
		if(g[v].count(i))	
			qq.push_back(i);
		else {
			go.push_back(i);
		}
	}
	q = qq;
	for(auto i : go) {
		dfs(i);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	maxdeg = n-1;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].insert(t);
		g[t].insert(f);
		if(f==1||t==1) maxdeg--;
	}
	auto solve = [&](int X) {
		for(int i = 1+X; i <= n; i++)
			q.push_back(i);
		while(!q.empty()) {
			int v = q.back();
			q.pop_back();
			dfs(v);
			if(X) mindeg++;
			else comps++;
		}
	};
	solve(1);
	solve(0);
	// cout << mindeg << " " << maxdeg << " " << comps << endl;
	int ok = mindeg <= k && k <= maxdeg && comps == 1;
	cout << (ok?"possible":"impossible") << '\n';
}
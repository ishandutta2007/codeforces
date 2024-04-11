#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1<<20;
int n, vis[maxn];
vector<int> g[maxn];
int C;
vector<int> l;
void dfs(int v, int p = -1) {
	if(g[v].size() == 1) l.push_back(v);
	vis[v] = 1;
	for(int i : g[v]) if(!vis[i]) dfs(i, v);
	else if(i != p) C = i;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		g[t].push_back(i);
		g[i].push_back(t);
	}
	vector<array<int, 2>> ans;
	vector<int> ins, Cs;
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		C=-1, l.clear();dfs(i);
		Cs.push_back(C);
		if(!l.empty()) {
			ins.push_back(l.back()); l.pop_back();
		} else ins.push_back(C);
		while(l.size()) ans.push_back({C, l.back()}), l.pop_back();
	}
	if(ins.size() > 1) {
	for(int i = 0; i < ins.size(); i++)
		ans.push_back({Cs[i], ins[(i+1)%ins.size()]});
	} else {
		if(Cs[0] != ins[0])
		ans.push_back({Cs[0], ins[0]});
	}
	cout << ans.size() << '\n';
	for(auto [l, r] : ans) cout << l << " " << r << '\n';
}
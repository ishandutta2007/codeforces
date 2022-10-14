#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
int n, m;
vector<int> g[2][maxn];
int solve1() {
	int ans = 1<<30;
	array<int, maxn> p;
	fill(all(p), 1<<30);
	p[1] = 0;
	for(int L = 0; L <= 20; L++) {
		priority_queue<array<int, 2>> pq;
		array<int, maxn> dist;
		fill(all(dist), 1<<30);
		auto relax = [&](int v, int d) {
			if(dist[v] <= d) return;
			dist[v] = d;
			pq.push({-dist[v], v});
		};
		for(int i = 1; i <= n; i++) if(p[i] != 1<<30) relax(i, p[i]);
		while(!pq.empty()) {
			auto [cst, v] = pq.top();
			cst *= -1;
			pq.pop();
			if(dist[v] < cst) continue;
			for(auto &i : g[L&1][v])
				relax(i, cst + 1);
		}
		ans = min(ans, dist[n] + (1<<L) - 1);
		p = dist;
	}
	if(ans == 1<<30) return -1;
	return ans;
}
namespace d2 {
	pair<int, int> dist[maxn][2];
};
int solve2() {
	using namespace d2;
	priority_queue<array<pair<int, int>, 2>> pq;
	for(int i = 0; i < maxn; i++) dist[i][0] = dist[i][1] = {1<<30, 0};
	auto relax = [&](int v, int t, pair<int, int> d) {
		if(dist[v][t] <= d) return;
		dist[v][t] = d;
		pq.push(array<pair<int, int>, 2>{ pair<int, int>{ -d.first, -d.second }, pair<int, int>{v, t}});
	};
	relax(1, 0, {0, 0});
	while(!pq.empty()) {
		auto trash = pq.top();
		auto cst = trash[0];
		cst.first *= -1, cst.second *= -1;
		int v = trash[1].first;
		int t = trash[1].second;
		pq.pop();
		if(dist[v][t] < cst) continue;
		for(auto &i : g[t][v])
			relax(i, t, pair<int, int>{cst.first, cst.second + 1});
		for(auto &i : g[t^1][v])
			relax(i, t^1, pair<int, int>{cst.first+1, cst.second + 1});
	}
	auto ans = min(dist[n][0], dist[n][1]);
	int a1 = ans.second;
	int a2 = 1;
	for(int i = 0; i < ans.first; i++) a2 = (a2+a2)%mod;
	return (a1 + mod-1 + a2)%mod;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	if(n == 1) {
		cout << "0\n";
		return 0;
	}
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[0][f].push_back(t);
		g[1][t].push_back(f);
	}
	int ans = solve1();
	if(solve1() < 0) ans = solve2();
	cout << ans%mod << '\n';
}
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include <bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 1e9 + 7;
int n, m;
vector<array<int, 3>> tp;
ll dist[maxn], x[maxn], y[maxn];
vector<int> g[maxn];
priority_queue<array<ll, 2>> pq;
void upd(int i, ll d) {
	if(dist[i] > d) {
		dist[i] = d;
		pq.push({-dist[i], i});
	}
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	ll x1, y1, x2, y2;cin >> x2 >> y2 >> x1 >> y1;
	tp.resize(m);
	for(int i = 0; i < m; i++) {
		cin >> tp[i][0] >> tp[i][1], tp[i][2] = i;
		x[i] = tp[i][0], y[i] = tp[i][1];
	}
	sort(all(tp));
	for(int i = 1; i < m; i++) {
		g[tp[i-1][2]].push_back(tp[i][2]);
		g[tp[i][2]].push_back(tp[i-1][2]);
	}
	for(auto &[x, y, z] : tp) swap(x, y);
	sort(all(tp));
	for(int i = 1; i < m; i++) {
		g[tp[i-1][2]].push_back(tp[i][2]);
		g[tp[i][2]].push_back(tp[i-1][2]);
	}
	memset(dist, 0x3f, sizeof dist);
	for(int i = 0; i < m; i++) {
		dist[i] = min(abs(x[i]-x2), abs(y[i]-y2));
		//cout << i << " " << abs(x[i]-x2) << " " << abs(y[i]-y2) << endl;
		pq.push({-dist[i], i});
	}
	while(!pq.empty()) {
		auto [cst, v] = pq.top();
		pq.pop();
		if(-cst > dist[v]) continue;
		//cout << v << " - " << dist[v] << endl;
		for(auto &i : g[v]) {
			upd(i, dist[v] + min(abs(x[i]-x[v]), abs(y[i]-y[v])));
			//cout << v << " -> " << i << " " << dist[v] + min(abs(x[i]-x[v]), abs(y[i]-y[v])) << endl;
		}
	}
	ll ans = abs(x1-x2) + abs(y1-y2);
	for(int i = 0; i < m; i++) {
		//cout << dist[i] << " " << abs(x[i]-x1)  << " " << abs(y[i]-y1) << endl;
		ans = min(ans,
		dist[i] + abs(x[i]-x1) + abs(y[i]-y1));
	}
	cout << ans << '\n';
}
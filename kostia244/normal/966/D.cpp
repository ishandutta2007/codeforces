#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<int> g[maxn];
queue<int> q;
int dist[maxn], p[maxn], F[maxn], bad[maxn];
void rec(int v) {
	if(v != 1) rec(p[v]);
	cout << v << " ";
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
		if(f == n) F[t] = 1;
		if(t == n) F[f] = 1;
	}
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto i : g[v]) if(dist[i] > dist[v]+1) {
			dist[i] = dist[v]+1;
			p[i] = v;
			q.push(i);
		}
	}
	int ans = dist[n];
	int d2 = 1<<30;
	array<int, 3> triple = {-1, -1, -1};
	for(int i = 1; i <= n; i++) {
		int cur = dist[i] + 1;
		array<int, 3> ct = {i, -1, -1};
		if(!F[i]) {
		bad[i] = bad[1] = i;
		for(auto &x : g[i]) bad[x] = i;
		int found = 0;
		//cout << i << " : ";
		//for(int i = 1; i <= n; i++) cout << bad[i] << " "; cout << '\n';
		for(auto &x : g[i]) {
			if(found) break;
			if(x != 1)
			for(auto &y : g[x]) {
				if(found) break;
				if(bad[y] != i) found = 1, ct = {i, x, y};
			}
		}
		if(!found) continue;
		cur += 3;
		}
		if(d2 > cur) {
			d2 = cur;
			triple = ct;
		}
	}
	//cout << ans << " " << d2 << '\n';
	if(ans > (1<<20) || d2 < ans) {
		if(d2 > (1<<20)) return cout << "-1\n", 0;
		cout << d2 << '\n';
		rec(triple[0]);
		cout << triple[1] << " " << triple[2] << " " << triple[0] << " " << n << '\n';
	} else cout << ans << '\n', rec(n);
}
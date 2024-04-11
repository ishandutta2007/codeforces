#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1<<17, mod = 924844033;
int n, m, q;
ll d[maxn], hd[maxn], cst[maxn];
vpi g[maxn];
vector<int> h[maxn];
int f[maxn], t[maxn], c[maxn];
void buildh() {
	for(int i = 0; i < m; i++) {
		cst[i] = d[f[i]] + c[i] - d[t[i]];
	}
}
vi Q[maxn];
void updateh() {
	memset(hd, 0x3f, sizeof hd);
	Q[0].pb(1);
	hd[1] = 0;
	//cout << "START\n";
	for(int d = 0; d < n; d++) {
		for(int i = 0; i < Q[d].size(); i++) {
			int v = Q[d][i];
			if(hd[v] < d) continue;
			//cout << v << " " << hd[v] << " " << d << '\n';
			for(auto &idx : h[v]) {
				int u = t[idx];
				//cout << u << " " << cst[idx] << '\n';
				if(hd[u] > hd[v] + cst[idx]) {
					hd[u] = hd[v] + cst[idx];
					if(hd[u] < n) {
						Q[hd[u]].pb(u);
						//cout << u << " to " << hd[u] <<'\n';
					}
				} 
			}
		}
		Q[d].clear();
	}
	//cout << "END\n";
	for(int i = 1; i <= n; i++) if(d[i] < d[100001]) d[i] += hd[i];
	buildh();
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++) {
		cin >> f[i] >> t[i] >> c[i];
		g[f[i]].pb({t[i], c[i]});
		h[f[i]].pb(i);
	}
	memset(d, 0x3f, sizeof d);
	{
	priority_queue<pair<ll, int>> q;
	for(q.push({d[1] = 0, 1}); !q.empty();) {
		auto [cost, v] = q.top();
		q.pop();
		cost *= -1;
		if(cost > d[v]) continue;
		for(auto [u, w] : g[v]) {
			if(d[u] > cost + w) {
				d[u] = cost + w;
				q.push({-d[u], u});
			}
		}
	}
	}
	buildh();
	int tp, x;
	while(q--) {
		cin >> tp >> x;
		if(tp == 1) cout << (d[x] >= d[100001] ? -1ll : d[x]) << '\n';
		else {
			for(int t, i = 0; i < x; i++) {
				cin >> t;
				cst[t-1]++;
				c[t-1]++;
			}
			updateh();
		}
	}
}
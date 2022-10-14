#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, l;
vi g[maxn];
vi gt[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int f, t, i = 1; i <= m; i++){
		cin >> f >> t;
		g[t].pb(f);
		gt[f].pb(t);
	}
	cin >> l;
	vi p(l);
	for(auto &i : p) cin >> i;
	int s = p.back();
	queue<int> q;
	vector<bool> used(n+33);
	vector<int> d(n+33);

	q.push(s);
	used[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	}
	int mn = 0, mx = 0;
	for(int i = 1; i < l; i++) {
		int u = p[i-1], v= p[i], c = 0;
		for(auto &i : gt[u]) {
			if(i==v) continue;
			if(d[i]==d[u]-1) {
				mx++;
				break;
			}
		}
		if(d[v]+1!=d[u]) mn++;
	}
	cout << mn << " " << mx << '\n';
	return 0;
}
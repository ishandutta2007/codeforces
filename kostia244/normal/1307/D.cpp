#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 2e5 + 555;
int n, m, k, d[2][maxn];
vi g[maxn];
vi a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	a.resize(k);
	for(auto &i : a) cin >> i;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	memset(d, -1, sizeof d);
	for(int k = 0; k < 2; k++) {
		queue<int> q;
		q.push(k?n:1);
		d[k][k?n:1]=0;
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(auto i : g[v]) {
				if(d[k][i]!=-1) continue;
				d[k][i] = d[k][v] + 1;
				q.push(i);
			}
		}
	}
	vpi x;
	for(auto i : a) {
		x.pb({d[0][i], i});
	}
	sort(rall(x));
	set<int, greater<int>> g;
	int ans = 0;
	for(auto t : x) {
		int i = t.second;
		if(!g.empty()) {
			ans = max(ans, d[0][i] + 1 + *g.begin());
		}
		g.insert(d[1][i]);
	}
	cout << min(ans, d[0][n]);
	return 0;
}
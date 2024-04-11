#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<ll, ll>
#define ll long long
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, f, t, mx = 0;
vi a, vs, dp1;
vector<vi> g, p;

void dfs(int v, int d) {
	vs[v] *= d;
	int m = 0, s = 0;
	for(auto& i : g[v]) {
		if(a[i]%d == 0 && vs[i]%d != 0) {
			dfs(i, d);
			if(m < dp1[i]) {
				s = m;
				m = dp1[i];
			} else if(s < dp1[i]) {
				s = dp1[i];
			}
		}
	}
	dp1[v] = m + 1;
	if(mx < (m + s + 1))
		mx = (m + s + 1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	vs.resize(n + 1, 1);
	a.resize(n + 1);
	dp1.resize(n + 1);
	g.resize(n + 1);
	p.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		cin >> f >> t, g[f].pb(t), g[t].pb(f);
	for(int i = 1; i<= n; i++) {
		int num = a[i];
		for(int d = 2; d * d <= num; d++) {
			if(num%d)
				continue;
			p[i].pb(d);
			while(num%d == 1)
				num /= d;
		}
		if(num != 1)
			p[i].pb(num);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < p[i].size(); j++)
			if(vs[i]%p[i][j])
				dfs(i, p[i][j]);
	cout << mx;
}
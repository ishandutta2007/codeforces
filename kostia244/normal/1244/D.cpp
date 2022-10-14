#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n;
vi c[3];
vvi g;
vi s;
vi col;

ll go(vi a) {
	col.assign(n+1, 0);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += c[a[i%3]][s[i]];
		col[s[i]] = a[i%3];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 3; i++) {
		c[i].resize(n + 1);
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int r = -1;
	for(int i = 1; i <= n; i++) {
		if(g[i].size() > 2) {
			cout << -1;
			return 0;
		}
		if(g[i].size() == 1)
			r = i;
	}
	int p = -1, i = 0;
	while(true) {
		s.pb(r);
		if(g[r][0]==p) {
			if(g[r].size()==1) {
				break;
			}
			swap(g[r][0], g[r][1]);
		}
		i++;
		p = r;
		r = g[r][0];
	}
	ll ans = LLONG_MAX;
	vi a = {0, 1, 2}, aa;
	do {
		ll t = go(a);
		if(t < ans)
			ans = t, aa = col;
	} while(next_permutation(all(a)));
	cout << ans << "\n";
	for(int i = 1; i <= n; i++)
		cout << aa[i]+1 << " ";
}
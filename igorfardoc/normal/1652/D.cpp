#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;
int lp[maxn + 1];
vi pr;
int ans;

void precalc() {
	for(int i = 2; i <= maxn; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= maxn; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = (ll)res * res % mod;
	if(b & 1) res = (ll)res * a % mod;
	return res;
}
int obr(int a) {
	return bin_pow(a, mod - 2);
}

vector<vector<array<int, 3>>> g;
int now[maxn + 1];

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

void go(int x, int y) {
	int g = gcd(x, y);
	x /= g;
	y /= g;
	while(x != 1) {
		int curr = lp[x];
		x /= curr;
		now[curr] = max(0, now[curr] - 1);
	}
	while(y != 1) {
		int curr = lp[y];
		y /= curr;
		now[curr]++;
	}
}

void dfs(int v, int p, int x, int y) {
	for(const auto& el : g[v]) {
		int u = el[0];
		int x = el[1];
		int y = el[2];
		if(u == p) continue;
		go(x, y);
		dfs(u, v, y, x);
	}
	if(p != -1) {
		go(x, y);
	}
}
void dfs2(int v, int p, int res) {
	ans = (ans + res) % mod;
	for(const auto& el : g[v]) {
		int u = el[0];
		int x = el[1];
		int y = el[2];
		if(u == p) continue;
		int here = (ll)res * obr(x) % mod;
		here = (ll)here * y % mod;
		dfs2(u, v, here);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	precalc();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		g.assign(n, {});
		for(int i = 0; i < n - 1; i++) {
			int v, u, x, y;
			cin >> v >> u >> x >> y;
			--v;
			--u;
			g[v].push_back({u, x, y});
			g[u].push_back({v, y, x});
		}
		for(int i = 1; i <= n; i++) {
			now[i] = 0;
		}
		dfs(0, -1, -1, -1);
		ans = 0;
		int res = 1;
		for(int i = 1; i <= n; i++) {
			res = (ll)res * bin_pow(i, now[i]) % mod;
		}
		dfs2(0, -1, res);
		cout << ans << '\n';
	}


}
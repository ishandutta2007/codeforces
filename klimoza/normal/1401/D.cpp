/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 1e5 + 7;

vector<int> g[N];
int sz[N];

vector<ll> val;

int n;

void dfs(int v, int last = -1) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == last) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
	if (last != -1)
		val.push_back(sz[v] * 1ll * (n - sz[v]));
}

ll mul(ll a, ll b) {
	a %= mod; b %= mod;
	return a * b % mod;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		val.clear();
		for (int i = 0; i < n; i++) {
			sz[i] = 0;
			g[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0);
		int m; cin >> m;
		vector<ll> p(m);
		for (int i = 0; i < m; i++)
			cin >> p[i];
		sort(rall(val));
		sort(rall(p));
		if (m < (n - 1)) {
			for (int i = 0; i < (n - 1 - m); i++)
				p.push_back(1);
		}
		if (m > (n - 1)) {
			ll cur = 1;
			reverse(all(p));
			while (p.size() >= (n - 1)) {
				cur = mul(cur, p.back());
				p.pop_back();
			}
			p.push_back(cur);
			reverse(all(p));
		}
		ll ans = 0;
		for (int i = 0; i < val.size(); i++) {
			ans = (ans + val[i] * p[i] % mod) % mod;
		}
		cout << ans << endl;
	}
	return;
}
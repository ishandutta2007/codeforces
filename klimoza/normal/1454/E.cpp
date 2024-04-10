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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

const int N = 2e5 + 2;

int p[N], d[N], tot[N];
vector<int> g[N];
bool used[N];

ll ans = 0;
int x = -1, y = -1;

void dfs(int v, int last = -1){
	tot[v] = 1;
	used[v] = true;
	for (int u : g[v]) {
		if (u == last) continue;
		if (used[u]) {
			x = v, y = u;
			continue;
		}
		p[u] = v;
		d[u] = d[v] + 1;
		dfs(u, v);
		tot[v] += tot[u];
	}
	for (int u : g[v]) {
		if (u == last) continue;
		if (mp(u, v) == mp(x, y) || mp(v, u) == mp(x, y)) continue;
		ans += tot[u] * 1ll * (tot[v] - tot[u] + 1);
	}
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			p[i] = 0, d[i] = 0;
			tot[i] = 0;
			g[i].clear();
			used[i] = false;
		}
		x = -1, y = -1; 
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b; a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0);
		ans /= 2;
		if (d[x] < d[y]) swap(x, y);
		ans += tot[x] * 1ll * (n - tot[x]);
		int lst = x;
		int v = p[x];
		while (v != y) {
			ans += (tot[v] - tot[lst]) * 1ll * (n - tot[v]);
			lst = v;
			v = p[v];
		}
		cout << ans << endl;
	}
	return;
}
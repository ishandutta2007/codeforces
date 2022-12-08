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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
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

const int N = 2e5 + 7;

int d[N], sz[N];
vector<int> g[N];

void dfs(int v, int last = -1) {
	sz[v] = 0;
	for (int u : g[v]) {
		if (u == last) continue;
		d[u] = d[v] + 1;
		dfs(u, v);
		sz[v] += sz[u] + 1;
	}
}


void solve() {
	d[0] = 0;
	int n, k; cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	vector<int> kek(n);
	for (int i = 0; i < n; i++) {
		kek[i] = d[i] - sz[i];
	}
	sort(rall(kek));
	ll ans = 0;
	for (int i = 0; i < k; i++)
		ans += kek[i];
	cout << ans << endl;
	return;
}
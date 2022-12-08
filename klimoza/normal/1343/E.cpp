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

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

const int N = 2e5 + 7;

int d1[N], d2[N], d3[N];
int n;
vector<int> g[N];

void djikstra(int s, int* d) {
	set<pair<int, int>> q;
	fill(d, d + n, inf0);
	d[s] = 0;
	for (int i = 0; i < n; i++)
		q.insert({ d[i], i });
	while (!q.empty()) {
		auto v = *q.begin();
		q.erase(q.begin());
		if (v.first == inf0) break;
		for (int u : g[v.second]) {
			if (d[u] > v.first + 1) {
				q.erase({ d[u], u });
				d[u] = v.first + 1;
				q.insert({ d[u], u });
			}
		}
	}
}


void solve() {
	int t; cin >> t;
	while (t--) {
		int m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		a--; b--; c--;
		for (int i = 0; i < n; i++)
			g[i].clear();
		vector<ll> p(m);
		for (ll& i : p) cin >> i;
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y; x--; y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		sort(all(p));
		vector<ll> pref(m + 1, 0);
		for (int i = 1; i <= m; i++) {
			pref[i] = pref[i - 1] + p[i - 1];
		}
		djikstra(a, d1);
		djikstra(b, d2);
		djikstra(c, d3);
		ll ans = inf;
		for (int i = 0; i < n; i++) {
			if (d1[i] + d2[i] + d3[i] > m) continue;
			ans = min(ans, pref[d2[i]] + pref[d1[i] + d3[i] + d2[i]]);
		}
		cout << ans << endl;
	}
	return;
}
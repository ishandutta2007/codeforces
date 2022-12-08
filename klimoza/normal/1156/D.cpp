#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

vector<pair<int, int>> g[N];
ll w[N], b[N], wb[N], bw[N];

void calc(int v, int last = -1) {
	w[v] = 0, b[v] = 0, wb[v] = 0, bw[v] = 0;
	for (auto u : g[v]) {
		if (u.first == last) continue;
		calc(u.first, v);
		if (u.second == 0) {
			w[v] += w[u.first] + 1;
			wb[v] += wb[u.first] + b[u.first];
		}
		else {
			b[v] += b[u.first] + 1;
			bw[v] += bw[u.first] + w[u.first];
		}
	}
}

ll ans = 0;

void dfs(int v, int last = -1) {
	ans += 2 * w[v] + 2 * b[v] + wb[v] + bw[v];
	ll d = 0;
	for (auto u : g[v]) {
		if (u.first == last) continue;
		dfs(u.first, v);
		if (u.second == 0) {
			ans += (w[u.first] + 1) * (w[v] - w[u.first] - 1);
			ans += (wb[v] - wb[u.first] - b[u.first]) * (w[u.first] + 1);
			ans += (w[u.first] + 1) * b[v];
		}
		else {
			ans += (b[u.first] + 1) * (b[v] - b[u.first] - 1);
			ans += (bw[v] - bw[u.first] - w[u.first]) * (b[u.first] + 1);
		}
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--; int w; cin >> w;
		g[a].push_back({ b, w });
		g[b].push_back({ a, w });
	}
	calc(0);
	dfs(0);
	cout << ans << endl;
}
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
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

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

const int N = 5e5 + 8;

vector<int> g[N];
int bg[N], ed[N], sz[N];

void calc(int v, int last = -1) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == last) continue;
		calc(u, v);
		sz[v] += sz[u];
	}
}

void dfs(int v, int last = -1) {
	int cur = 0;
	vector<int> suff(g[v].size());
	if (g[v].empty()) return;
	suff.back() = 0;
	for (int i = g[v].size() - 2; i >= 0; i--) {
		suff[i] = suff[i + 1];
		if (g[v][i + 1] != last) suff[i] += sz[g[v][i + 1]];
	}
	int t = 0;
	for (int i = g[v].size() - 1; i >= 0; i--) {
		if (g[v][i] == last) {
			t = 1;
			continue;
		}
		bg[g[v][i]] = ed[v] - (g[v].size() - i) + t;
		ed[g[v][i]] = bg[g[v][i]] + 1 + 2 * suff[i] + g[g[v][i]].size();
		dfs(g[v][i], v);
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	calc(0);
	bg[0] = 1;
	ed[0] = 2 + g[0].size();
	dfs(0);
	for (int i = 0; i < n; i++) {
		cout << bg[i] << " " << ed[i] << endl;
	}
	return;
}
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

const int N = 2e5 + 8;

int d[N];
pair<int, int> d1[N];
pair<int, pair<int, int>> d2[N];

vector<int> g[N];

struct Item {
	int a, b, c;
	Item() {}
	Item(int a, int b, int c) : a(a), b(b), c(c) {}
};

pair<int, Item> ans = { -inf0, {-1, -1, -1} };

void calc(int v, int last = -1) {
	if (last == -1) d[v] = 0;
	else d[v] =  d[last] + 1;
	d1[v] = { d[v], v };
	d2[v] = { -1, {-1, -1} };
	for (int u : g[v]) {
		if (u == last) continue;
		calc(u, v);
		d1[v] = max(d1[v], d1[u]);
		d2[v] = max(d2[v], d2[u]);
	}
	sort(all(g[v]), [&](int x, int y) {return d[x] > d[y]; });
	if(last != -1)
		g[v].pop_back();
	if (g[v].empty())
		d2[v] = { -inf0, {-1, -1} };
	else {
		if (g[v].size() > 1) {
			sort(all(g[v]), [&](int x, int y) {return d1[x].first > d1[y].first; });
			pair<int, int> t1 = d1[g[v][0]];
			pair<int, int> t2 = d1[g[v][1]];
			d2[v] = max(d2[v], mp( t1.first + t2.first - d[v], mp(t1.second, t2.second) ));
		}
		else {
			d2[v] = max(d2[v], mp( d1[v].first, mp(d1[v].second, v) ));
		}
	}
	//cout << v + 1 << " " << d2[v].first << " " << d2[v].second.first + 1 << " " << d2[v].second.second + 1 << endl;
	sort(all(g[v]), [&](int x, int y) {return d1[x].first > d1[y].first; });
	if (g[v].size() >= 3) {
		if (ans.first < d1[g[v][0]].first + d1[g[v][1]].first + d1[g[v][2]].first - 3 * d[v]) {
			ans.first = d1[g[v][0]].first + d1[g[v][1]].first + d1[g[v][2]].first - 3 * d[v];
			ans.second = { d1[g[v][0]].second, d1[g[v][1]].second, d1[g[v][2]].second };
		}
	}
	if (g[v].size() >= 2) {
		if (ans.first < d1[g[v][0]].first + d1[g[v][1]].first - 2 * d[v]) {
			ans.first = d1[g[v][0]].first + d1[g[v][1]].first - 2 * d[v];
			ans.second = { d1[g[v][0]].second, d1[g[v][1]].second, v };
		}
		if (ans.first < d1[g[v][1]].first + d2[g[v][0]].first - 2 * d[v]) {
			ans.first = d2[g[v][0]].first + d1[g[v][1]].first - 2 * d[v];
			ans.second = { d1[g[v][1]].second, d2[g[v][0]].second.first, d2[g[v][0]].second.second };
		}
		for (int i = 1; i < g[v].size(); i++) {
			if (ans.first < d1[g[v][0]].first + d2[g[v][i]].first - 2 * d[v]) {
				ans.first = d2[g[v][i]].first + d1[g[v][0]].first - 2 * d[v];
				ans.second = { d1[g[v][0]].second, d2[g[v][i]].second.first, d2[g[v][i]].second.second };
			}
		}
	}
	if (g[v].size() >= 1) {
		if (ans.first < d2[g[v][0]].first - d[v]) {
			ans.first = d2[g[v][0]].first - d[v];
			ans.second = { v, d2[g[v][0]].second.first, d2[g[v][0]].second.second };
		}
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
	cout << ans.first << endl;
	cout << ans.second.a + 1 << " " << ans.second.b + 1 << " " << ans.second.c + 1 << endl;
	return;
}
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

const int N = 1e5 + 7;
const int L = 20;
int p[N], sz[N];

void build(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i; sz[i] = 1;
	}
}

int get_par(int k) {
	if (p[k] == k) return k;
	return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
	a = get_par(a); b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	p[b] = a;
}

vector<pair<int, int>> g[N];
int tin[N], tout[N];
int tm = 0;
int pr[N][L], mx[N][L];

void calc(int v, pair<int, int> last = { -1, -1 }) {
	tin[v] = tm++;
	if (last.first != -1) {
		pr[v][0] = last.first;
		mx[v][0] = last.second;
	}
	else {
		pr[v][0] = v;
		mx[v][0] = 0;
	}
	for (int l = 1; l < L; l++) {
		pr[v][l] = pr[pr[v][l - 1]][l - 1];
		mx[v][l] = max(mx[pr[v][l - 1]][l - 1], mx[v][l - 1]);
	}
	for (pair<int, int> u : g[v]) {
		if (u.first == last.first) continue;
		calc(u.first, { v, u.second });
	}
	tout[v] = tm++;
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if (upper(a, b)) return a;
	if (upper(b, a)) return b;
	int x = a;
	int c = L - 1;
	while (c >= 0) {
		if (!upper(pr[x][c], b)) x = pr[x][c];
		c--;
	}
	return pr[x][0];
}

int get(int l, int r) {
	if (l == r) return 0;
	int res = 0;
	int c = L - 1;
	while (c >= 0) {
		if (!upper(pr[l][c], r)) {
			res = max(res, mx[l][c]);
			l = pr[l][c];
		}
		c--;
	}
	res = max(res, mx[l][0]);
	return res;
}

void solve() { 
	int n, m; cin >> n >> m;
	vector<pair<pair<int, int>, pair<int, int>>> ed(m);
	for (int i = 0; i < m; i++) {
		cin >> ed[i].first.first >> ed[i].first.second >> ed[i].second.first; ed[i].first.first--; ed[i].first.second--;
		ed[i].second.second = i;
	}
	build(n);
	sort(all(ed), [](pair<pair<int, int>, pair<int ,int>> x, pair<pair<int, int>, pair<int, int>> y) {return x.second < y.second; });
	vector<bool> used(ed.size(), false);
	for (int i = 0; i < ed.size(); i++) {
		if (get_par(ed[i].first.first) != get_par(ed[i].first.second)) {
			g[ed[i].first.first].push_back({ ed[i].first.second, ed[i].second.first });
			g[ed[i].first.second].push_back({ ed[i].first.first, ed[i].second.first });
			used[i] = true;
		}
		merge(ed[i].first.first, ed[i].first.second);
	}
	calc(0);
	vector<pair<int, int>> ans;
	for (int i = 0; i < ed.size(); i++) {
		if (!used[i]) {
			auto u = ed[i];
			int l = lca(ed[i].first.first, ed[i].first.second);
			int res = max(get(u.first.first, l), get(u.first.second, l));
			ans.push_back({ ed[i].second.second, res });
		}
	}
	sort(all(ans));
	for (auto u : ans) cout << u.second << " ";
}
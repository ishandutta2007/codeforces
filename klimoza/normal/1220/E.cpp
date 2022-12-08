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
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

int tin[N];
int tout[N];
bool used[N];
int up[N];
int timer = 0;
vector<int> g[N];
set<pair<int, int>> bridge;

void dfs(int v, int last = -1) {
	used[v] = true;
	tin[v] = up[v] = timer++;
	for (int u : g[v]) {
		if (u == last) continue;
		if (!used[u]) {
			dfs(u, v);
			if (up[u] == tin[u]) {
				bridge.insert({ v, u });
				bridge.insert({ u, v });
			}
		}
		up[v] = min(up[v], up[u]);
	}
	//cout << v + 1 << " " << tin[v] << " " << up[v] << endl;
	tout[v] = timer++;
}

ll w[N];
vector<int> newG[N];

int p[N], sz[N];

void makeDSU(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
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
	w[a] += w[b];
	p[b] = a;
}

bool sub[N];

pair<ll, ll> findAns(int v, int last = -1) {
	//cout << v + 1 << endl;
	if (sz[v] > 1) sub[v] = true;
	vector<pair<ll, ll>> sons;
	for (int u : newG[v]) {
		if (u == last) continue;
		sons.push_back(findAns(u, v));
		sub[v] |= sub[u];
	}
	pair<ll, ll> re = { 0, w[v] };
	if (sub[v]) {
		re.first = w[v];
		for (pair<ll, ll> u : sons) {
			re.first += u.first;
		}
	}
	ll su = 0;
	for (pair<ll, ll> u : sons) {
		su += u.first;
	}
	for (pair<ll, ll> u : sons) {
		re.second = max(re.second, su - u.first + u.second + w[v]);
	}
	//cout << v + 1 << " " << re.first << " " << re.second << endl;
	return re;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++ ) {
		cin >> w[i];
	}
	vector<pair<int, int>> ed(m);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		ed[i] = { u, v };
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	makeDSU(n);
	for (int i = 0; i < m; i++) {
		if (bridge.find(ed[i]) == bridge.end()) {
			merge(ed[i].first, ed[i].second);
			//cout << ed[i].first << " " << ed[i].second << endl;
			//newG[ed[i].first].push_back(ed[i].second);
			//newG[ed[i].second].push_back(ed[i].first);
		}
	}
	for (int i = 0; i < m; i++) {
		if (get_par(ed[i].first) != get_par(ed[i].second)) {
			newG[get_par(ed[i].first)].push_back(get_par(ed[i].second));
			newG[get_par(ed[i].second)].push_back(get_par(ed[i].first));
		}
	}
	int st;
	cin >> st; st--;
	cout << findAns(get_par(st)).second << endl;
}
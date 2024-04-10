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

vector<int> p, sz;

void build(int n) {
	p.clear(); p.resize(n); sz.clear(); sz.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i; sz[i] = 1;
	}
}

int get_par(int k) {
	if (k == p[k]) return k;
	return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
	a = get_par(a); b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	p[b] = a;
}

const int N = 1e5 + 7;

int n;
vector<int> g[N];

ll Prim(int s) {
	//cout << s + 1 << endl;
	deque<pair<int, int>> f;
	int id = 0;
	sort(all(g[s]));
	vector<bool> used(n);
	for (int i = 0; i < n; i++) {
		if (id != g[s].size() && g[s][id] == i) {
			id++;
			f.push_back({ i, 1 });
			//cout << i + 1 << endl;
		}
		else {
			f.push_front({ i, 0 });
		}
	}
	ll ans = 0;
	while (!f.empty()) {
		auto v = f.front();
		f.pop_front();
		if (used[v.first]) continue;
		used[v.first] = true;
		ans += v.second;
		int j = 0;
		for (int i : g[s]) {
			if (used[i] || j == g[v.first].size()) continue;
			while (j != g[v.first].size() && g[v.first][j] < i) j++;
			if (g[v.first][j] == i) {
				continue;
			}
			f.push_front({ i, 0 });
		}
	}
	return ans;
}

void solve() {
	cin >> n;
	int m; cin >> m;
	vector<pair<int, int>> ed(m);
	build(n);
	for (int i = 0; i < n; i++) g[i] = vector<int>();
	for (int i = 0; i < m; i++) {
		cin >> ed[i].first >> ed[i].second; ed[i].first--; ed[i].second--;
		merge(ed[i].first, ed[i].second);
	}
	if (sz[get_par(0)] != n) cout << 0 << endl;
	else {
		vector<pair<int, int>> s(n);
		for (int i = 0; i < n; i++) s[i].second = i;
		for (auto u : ed) {
			g[u.first].push_back(u.second);
			g[u.second].push_back(u.first);
			s[u.first].first++; s[u.second].first++;
		}
		for (int i = 0; i < n; i++) sort(all(g[i]));
		sort(all(s));
		cout << Prim(s[0].second) << endl;
	}
}
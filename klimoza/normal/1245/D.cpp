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

const int N = 2e3 + 7;
ll p[N], sz[N];
pair<ll, int> mn[N];
bool st[N];
ll c[N], k[N];
pair < ll , ll > x[N];

void build(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i; sz[i] = 1; mn[i] = { c[i], i };
		st[i] = true;
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
	p[b] = a; sz[a] += sz[b];
	auto u = max(mn[a], mn[b]);
	st[u.second] = false;
	mn[a] = min(mn[a], mn[b]);
}

ll dist(int i, int j) {
	return abs(x[i].first - x[j].first) + abs(x[i].second - x[j].second);
}

struct Edge {
	int a, b;
	ll w;
	Edge() {}
	Edge(int a, int b, ll w) :a(a), b(b), w(w) {}
};

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> x[i].second;
	}
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) cin >> k[i];
	build(n);
	vector<Edge> ed;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ed.push_back({ i, j, dist(i, j) * (k[i] + k[j]) });
		}
	}
	sort(all(ed), [](Edge a, Edge b) {return a.w < b.w; });
	vector<pair<int, int>> ans;
	ll sum = 0;
	for (auto u : ed) {
		if (get_par(u.a) == get_par(u.b)) continue;
		int f1 = get_par(u.a);
		int f2 = get_par(u.b);
		if (max(mn[f1].first, mn[f2].first) >= u.w) {
			sum += u.w;
			ans.push_back({ u.a, u.b });
			merge(f1, f2);
		}
	}
	vector<int> ver;
	for (int i = 0; i < n; i++) {
		if (st[i]) {
			ver.push_back(i);
			sum += c[i];
		}
	}
	cout << sum << endl;
	cout << ver.size() << endl;
	for (int i : ver) cout << i + 1 << " ";
	cout << endl;
	cout << ans.size() << endl;
	for (auto u : ans) cout << u.first + 1 << " " << u.second + 1 << endl;
}
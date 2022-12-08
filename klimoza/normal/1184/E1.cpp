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

void solve() { 
	int n, m; cin >> n >> m;
	vector<pair<pair<int, int>, int>> ed(m);
	for (int i = 0; i < m; i++) {
		cin >> ed[i].first.first >> ed[i].first.second >> ed[i].second;
	}
	build(n);
	int u, v;
	u = ed[0].first.first;
	v = ed[0].first.second;
	swap(ed[0], ed.back()); ed.pop_back();
	sort(all(ed), [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {return x.second < y.second; });
	int ans = -1;
	for (int i = 0; i < ed.size(); i++) {
		if (get_par(u) == get_par(v)) {
			ans = ed[i - 1].second;
			break;
		}
		merge(ed[i].first.first, ed[i].first.second);
	}
	if (get_par(u) == get_par(v) && ans == -1) ans = ed.back().second;
	if (ans == -1) ans = 1e9;
	cout << ans << endl;
}
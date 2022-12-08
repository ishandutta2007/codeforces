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
#include <string>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 2e5 + 1;

int p[N], sz[N];

void build() {
	for (int i = 0; i < N; i++) {
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
	p[b] = a;
}

struct Edge {
	ll w;
	int a, b;
	Edge() {}
	Edge(ll w, int a, int b) : w(w), a(a), b(b) {}
};

void solve() {
	build();
	int n, m; cin >> m >> n;
	vector<ll> a(m), b(n);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<Edge> ed;
	ll tot = 0;
	for (int i = 0; i < m; i++) {
		int c; cin >> c;
		for (int j = 0; j < c; j++) {
			int k; cin >> k; k--;
			tot += a[i] + b[k];
			ed.push_back(Edge(a[i] + b[k], i, m + k));
		}
	}
	sort(all(ed), [](Edge x, Edge y) {return x.w > y.w; });
	for (auto u : ed) {
		if (get_par(u.a) == get_par(u.b)) continue;
		tot -= u.w;
		merge(u.a, u.b);
	}
	cout << tot << endl;
	return;
}
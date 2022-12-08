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
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 1e5 + 1;

bool better(pair<ll, ll> a, pair<ll, ll> x, pair<ll, ll> y) {
	return (y.second - a.second) * (x.first - a.first) > (x.second - a.second) * (y.first - a.first);
}

vector<int> g[N];
const int L = 20;

int tin[N], tout[N], up[N][L];

int timer = 0;

void dfs(int v, int last = -1) {
	tin[v] = timer++;
	if (last == -1) up[v][0] = v;
	else up[v][0] = last;
	for (int l = 1; l < L; l++)
		up[v][l] = up[up[v][l - 1]][l - 1];
	for (int u : g[v]) {
		if (u == last) continue;
		dfs(u, v);
	}
	tout[v] = timer++;
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if (upper(a, b)) return a;
	if (upper(b, a)) return b;
	for (int l = L - 1; l >= 0; l--) {
		if (!upper(up[a][l], b))
			a = up[a][l];
	}
	return up[a][0];
}

void solve() {
	int n; cin >> n;
	vector<pair<ll, ll>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	vector<int> q;
	for (int i = n - 1; i >= 0; i--) {
		if (q.empty()) q.push_back(i);
		else {
			while (q.size() > 1) {
				pair<ll, ll> x = a[q[q.size() - 2]];
				pair<ll, ll> y = a[q.back()];
				//if (i == n - 3) cout << x.first << " " << x.second << " " << y.first << " " << y.second << " " << a[i].first << " " << a[i].second << endl;
				if (better(a[i], y, x))
					q.pop_back();
				else
					break;
			}
			//cout << q.back() << " " << i <<" " << q.size() << endl;
			g[q.back()].push_back(i);
			g[i].push_back(q.back());
			q.push_back(i);
		}
	}
	dfs(n - 1);
	int m; cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y; x--; y--;
		cout << lca(x, y) + 1 << " ";
	}
	return;
}
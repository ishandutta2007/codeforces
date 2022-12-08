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

mt19937 mrand(random_device{}());

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

const int N = 3e5 + 7;

vector<int> g[N];
int sz[N], p[N];

pair<int, int> kek = { -1, -1 };

int n;

int leaf = -1;

int build_sz(int v, int last = -1) {
	p[v] = last;
	sz[v] = 1;
	int mem = -1;
	for (int u : g[v]) {
		if (u == last) continue;
		mem = build_sz(u, v);
		sz[v] += sz[u];
	}
	if (sz[v] == 1)
		mem = v;
	if (sz[v] * 2 == n) {
		kek = { p[v], v };
		leaf = mem;
	}
	return mem;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		kek = { -1, -1 };
		for (int i = 0; i < n; i++) {
			g[i].clear();
			sz[i] = 0;
		}
		pair<int, int> lol;
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b; a--; b--;
			lol = { a, b };
			g[a].push_back(b);
			g[b].push_back(a);
		}
		build_sz(0);
		if (kek.first == -1) {
			cout << lol.first + 1 << " " << lol.second + 1 << endl;
			cout << lol.first + 1 << " " << lol.second + 1 << endl;
		}
		else {
			cout << p[leaf] + 1 << " " << leaf + 1 << endl;
			cout << kek.first + 1 << " " << leaf + 1 << endl;
		}
	}
	return;
}
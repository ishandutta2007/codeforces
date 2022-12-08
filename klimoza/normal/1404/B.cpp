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

const int N = 1e5 + 2;

vector<int> g[N];
int d[N];

void dfs(int v, int last = -1) {
	if (last == -1) d[v] = 0;
	else d[v] = d[last] + 1;
	for (int u : g[v]) {
		if (u == last) continue;
		dfs(u, v);
	}
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, a, b, da, db;
		cin >> n >> a >> b >> da >> db;
		a--; b--;
		for (int i = 0; i < n; i++)
			g[i].clear();
		fill(d, d + n, 0);
		for (int i = 1; i < n; i++) {
			int x, y; cin >> x >> y; x--; y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if (da * 2 >= db) cout << "Alice\n";
		else {
			dfs(a);
			if (d[b] <= da) cout << "Alice\n";
			else {
				int x = 0;
				for (int i = 0; i < n; i++) {
					if (d[i] > d[x]) x = i;
				}
				dfs(x);
				int m = 0;
				for (int i = 0; i < n; i++) {
					m = max(m, d[i]);
				}
				if (da * 2 >= m) cout << "Alice\n";
				else cout << "Bob\n";
			}
		}
	}
	return;
}
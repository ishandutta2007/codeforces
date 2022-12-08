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

const int N = 1e6 + 1;

vector<int> g[N], rg[N];
int n, m;

int d[N], sz[N];
bool used[N];

void bfs(int s) {
	deque<int> q;
	q.push_back(s);
	fill(used, used + N, false);
	fill(d, d + N, 2e9);
	d[s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		if (used[v]) continue;
		used[v] = true;
		for (int u : rg[v]) {
			sz[u]--;
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				q.push_back(u);
			}
			if (!sz[u] && d[u] > d[v]) {
				bool fl = true;
				for (int k : g[u])
					if (d[k] != d[v])
						fl = false;
				if (fl) {
					d[u] = d[v];
					q.push_front(u);
				}
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	fill(sz, sz + N, 0);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		sz[a]++;
		rg[b].push_back(a);
	}
	int s, t; cin >> s >> t;
	s--; t--;
	bfs(t);
	if (d[s] == 2e9) cout << -1 << endl;
	else cout << d[s] << endl;
	return;
}
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

const int N = 5e3 + 2;

int sz[N];

bool used[N];
bool taken[N];

vector<int> g[N];

vector<int> rv[N];

void makerv(int v, int s) {
	rv[v].push_back(s);
	used[v] = true;
	sz[s]++;
	for (int u : g[v]) {
		if (used[u]) continue;
		makerv(u, s);
	}
}

int ans = -1;

void dfs(int v) {
	used[v] = true;
	if(!taken[v]){
	taken[v] = true;
	for (int k : rv[v])
		sz[k]--;
	}
	for (int u : g[v]) {
		if (!used[u])
			dfs(u);
	}
}

void add(int x) {
	ans++;
	fill(used, used + N, false);
	dfs(x);
}

void solve() {
	fill(sz, sz + N, 0);
	fill(taken, taken + N, false);
	int n, m; cin >> n >> m;
	int s; cin >> s; s--;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		fill(used, used + N, false);
		makerv(i, i);
	}
	add(s);
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++) {
		sort(all(p), [&](int a, int b) {return sz[a] > sz[b]; });
		bool fl = false;
		for (int j : p) {
			if (!taken[j]) {
				add(j);
				fl = true;
				break;
			}
		}
		if (!fl)
			break;
	}
	cout << ans << endl;
	return;
}
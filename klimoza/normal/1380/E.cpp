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

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1009;
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

const int N = 2e5 + 7;

map<int, int> f[N];

vector<int> g[N];

int t[N], p[N], sz[N];

int get_par(int k) {
	if (p[k] == k) return k;
	return p[k] = get_par(p[k]);
}

int ans = 0;

int n;

void merge(int a, int b) {
	a = get_par(a); b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	for (int i : g[b]) {
		if (i && get_par(t[i - 1]) == a) ans--;
		if ((i != n - 1) && get_par(t[i + 1]) == a) ans--;
		g[a].push_back(i);
	}
	g[b].clear();
	sz[a] += sz[b];
	p[b] = a;
}

void solve(){
	int m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i]; t[i]--;
		g[t[i]].push_back(i);
	}
	for (int i = 1; i < n; i++) {
		if (t[i] != t[i - 1]) {
			ans++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < m - 1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		merge(a, b);
		cout << ans << endl;
	}
	return;
}
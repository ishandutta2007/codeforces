//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
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
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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

const int N = 5e5 + 2;

int p[N], sz[N];
bool have[N];

void build() {
	for (int i = 0; i < N; i++) {
		p[i] = i;
		sz[i] = 1;
		have[i] = false;
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

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}

void solve() {
	build();
	int n, m; cin >> n >> m;
	vector<pair<int, int>> g(n, mp(-1, -1));
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		cin >> g[i].first; g[i].first--;
		if (k == 2) {
			cin >> g[i].second;
			g[i].second--;
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int a = g[i].first;
		int b = g[i].second;
		if (g[i].second == -1) {
			b = m;
		}
		if (get_par(a) == get_par(b)) continue;
		merge(a, b);
		ans.push_back(i);
	}
	ll t = ans.size();
	cout << bp(2, t) << " " << t << endl;
	for (int i : ans)
		cout << (i + 1) << " ";
	return;
}
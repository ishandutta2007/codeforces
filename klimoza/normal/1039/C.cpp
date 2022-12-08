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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
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

ll bp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int cnt;

const int N = 5e5 + 6;
int pp[N], sz[N];

void build(int n) {
	for (int i = 0; i < n; i++) {
		pp[i] = i;
		sz[i] = 1;
	}
}

int get_par(int k) {
	if (k == pp[k]) return k;
	return pp[k] = get_par(pp[k]);
}

void  merge(int a, int b) {
	a = get_par(a); b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	pp[b] = a;
	cnt--;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	cnt = n;
	ll tot = 1ll << k;
	vector<ll> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	vector<pair<int, int>> ed(m);
	vector<ll> kek(m);
	vector<ll> x;
	for (int i = 0; i < m; i++) {
		cin >> ed[i].first >> ed[i].second;
		ed[i].first--; ed[i].second--;
		kek[i] = p[ed[i].first] ^ p[ed[i].second];
		x.push_back(kek[i]);
	}
	sort(all(x));
	x.erase(unique(all(x)), x.end());
	map<ll, int> f;
	for (int i = 0; i < x.size(); i++)
		f[x[i]] = i;
	vector<vector<pair<int, int>>> lol(x.size());
	for (int i = 0; i < m; i++) {
		lol[f[kek[i]]].push_back(ed[i]);
	}
	ll ans = ((tot - (ll)x.size()) % mod) * 1ll * bp(2, n) % mod;
	int t = x.size();
	build(n);
	for (int i = 0; i < t; i++) {
		cnt = n;
		for (auto u : lol[i]) {
			merge(u.first, u.second);
		}
		ans = (ans + bp(2, cnt)) % mod;
		for (auto u : lol[i]) {
			pp[u.first] = u.first;
			pp[u.second] = u.second;
			sz[u.first] = sz[u.second] = 1;
		}
	}
	cout << ans << endl;
	return;
}
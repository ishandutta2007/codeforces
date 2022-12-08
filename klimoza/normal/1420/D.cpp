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

const int N = 3e5 + 7;

ll fac[N], rev[N];

ll add(ll a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = mul(res, a);
		a = mul(a, a);
		k >>= 1;
	}
	return res;
}

void build() {
	fac[0] = 1;
	for (ll i = 1; i < N; i++)
		fac[i] = mul(fac[i - 1], i);
	rev[N - 1] = bp(fac[N - 1], mod - 2);
	for (ll i = N - 2; i >= 0; i--)
		rev[i] = mul(rev[i + 1], i + 1);
}

ll C(ll n, ll k) {
	if (k > n) return 0;
	return mul(fac[n], mul(rev[n - k], rev[k]));		
}

void solve() {
	build();
	int n, k; cin >> n >> k;
	vector<pair<int, int>> ed;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		ed.push_back({ l, -1 });
		ed.push_back({ r, 1 });
	}
	ll s = 0;
	int cnt = 0;
	sort(all(ed));
	for (auto u : ed) {
		if (u.second == -1) {
			s = add(s, C(cnt, k - 1));
			cnt++;
		}
		else {
			cnt--;
		}
	}
	cout << s << endl;
	return;
}
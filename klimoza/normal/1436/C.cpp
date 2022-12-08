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
const double eps = 1e-5;
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

const int N = 1e3 + 2;

ll fac[N], rev[N];

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
		fac[i] = mul(i, fac[i - 1]);
	rev[N - 1] = bp(fac[N - 1], mod - 2);
	for (ll i = N - 2; i >= 0; i--)
		rev[i] = mul(rev[i + 1], i + 1);
}

ll A(ll n, ll k) {
	if (k > n || n < 0 || k < 0) return 0;
	return mul(fac[n], rev[n - k]);
}

void solve() {
	build();
	int n, x, pos;
	cin >> n >> x >> pos;
	int left = 0;
	int right = n;
	int c1 = 0, c2 = 0;
	while (left < right) {
		int middle = (left + right) / 2;
		if (middle < pos)
			c1++;
		else if(middle > pos)
			c2++;
		if (middle <= pos)
			left = middle + 1;
		else
			right = middle;
	}
	cout << mul(fac[n - c1 - c2 - 1], mul(A(x - 1, c1), A(n - x, c2)));
	return;
}
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
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
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

const int L = 63;

ll u[L];

int getMaxBit(ll x) {
	int cnt = -1;
	while (x) {
		cnt++;
		x >>= 1;
	}
	return cnt;
}

void norm(ll& a, ll mod) {
	if (a < 0) a = -(abs(a) % mod);
	else a = a % mod;
}

void add(ll& a, ll b, ll mod) {
	norm(a, mod); norm(b, mod);
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
}

ll mul(ll a, ll b, ll mod) {
	norm(a, mod); norm(b, mod);
	ll res = 0;
	ll kek = 1;
	if (b < 0) kek *= -1;
	if (a < 0) kek *= -1;
	a = abs(a); b = abs(b);
	while (b) {
		if(b & 1)
			res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return kek * res;
}

void solve() {
	int q; cin >> q;
	fill(u, u + L, 0);
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			ll k, x; cin >> x >> k;
			int i = getMaxBit(x);
			//cout << i << endl;
			add(u[i], k, (1ll << (i + 1)) - (1ll << i));
		}
		else if (tp == 2) {
			ll k, x; cin >> x >> k;
			int i = getMaxBit(x);
			ll cur = 1;
			//cout << i << endl;
			for (int j = i; j < L; j++) {
				add(u[j], mul(cur, k, (1ll << (j + 1)) - (1ll << j)), (1ll << (j + 1)) - (1ll << j));
				cur *= 2;
			}
		}
		else {
			ll x; cin >> x;
			int i = getMaxBit(x);
			ll mod = (1ll << (i + 1)) - (1ll << i);
			ll j = (x - (1ll << i) + u[i]) % mod;
			for (; i >= 0; i--) {
				cout << (1ll << i) + (j - u[i] + mod) % mod << " ";
				j >>= 1;
				if (i)
					mod = (1ll << i) - (1ll << (i - 1));
			}
			cout << endl;
		}
	}
	return;
}
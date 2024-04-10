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

struct Item {
	ll a, b, c;
	Item() {}
	Item(ll a, ll b, ll c) : a(a), b(b), c(c) {}
};

ll foo(ll a, int i, ll l, ll r) {
	if (r - l == 1) return l;
	i -= 2;
	if (a < (1ll << i)) return foo(a, i, l, l + (1ll << i));
	if (a < (2ll << i)) return foo(a - (1ll << i), i, l + (2ll << i), l + (3ll << i));
	if (a < (3ll << i)) return foo(a - (2ll << i), i, l + (3ll << i), r);
	return foo(a - (3ll << i), i, l + (1ll << i), l + (2ll << i));
}

ll get(ll m) {
	ll n = (m - 1) / 3;
	ll i = 0;
	ll a = 0, b = 0;
	while (true) {
		if (n >= (1ll << i)) {
			n -= (1ll << i);
			i += 2;
		}
		else {
			a = (1ll << i) + n;
			b = foo(n, i, (1ll << (i + 1)), (1ll << (i + 2)));
			break;
		}
	}
	//cout << a << " " << b << endl;
	ll c = a ^ b;
	Item kek = Item(a, b, c);
	if (m % 3 == 0) return c;
	else if (m % 3 == 1) return a;
	else return b;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		ll m; cin >> m;
		cout << get(m) << endl;
	}
	return;
	set<ll> kek;
	vector<ll> p;
	int cnt = 0;
	for (int a = 1; ; a++) {
		if (kek.find(a) != kek.end()) continue;
		for (int b = 1; ; b++) {
			if (a == b) continue;
			if (kek.find(b) != kek.end()) continue;
			if (kek.find(a ^ b) != kek.end()) continue;
			p.push_back(a);
			p.push_back(b);
			p.push_back(a ^ b);
			kek.insert(a);
			kek.insert(b);
			kek.insert(a ^ b);
			cnt += 3;
			//cout << a << " " << b << " " << (a^b) << endl;
			if (cnt >= 1000) break;
			break;
		}
		if(cnt >= 1000) break;
	}
	for (int i = 0; i < p.size(); i++) {
		ll kek = get(i + 1);
		if (kek != p[i]) {
			cout << i << " " << kek << " "  << p[i] << endl;
			return;
		}
	}
	return;
}
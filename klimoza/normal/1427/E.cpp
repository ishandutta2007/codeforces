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

struct Item {
	ll l, r;
	char c;
	Item() {}
	Item(ll l, ll r, char c) : l(l), r(r), c(c) {}
};

vector<Item> ans;

void pr() {
	cout << ans.size() << endl;
	for (auto u : ans) {
		cout << u.l << " " << u.c << " " << u.r << endl;
	}
}

void solve() {
	ll x; cin >> x;
	set<ll> kek = { x };
	set<ll> p;
	ll c = 1;
	ll tmp = -1;
	if (x & 2) {
		ans.push_back(Item(x, x, '+'));
		kek.insert(2 * x);
		ans.push_back(Item(x, 2 * x, '^'));
		kek.insert(x ^ (2 * x));
		x = (x ^ (2 * x));
	}
//	cout << x << endl;
	if (x != 1) {
		ll l = 0;
		for (int i = 0; i < 55; i++) {
			if ((1ll << i) & x)
				l = i;
		}
		//cout << l << endl;
		for (ll i = 1; i <= l; i++) {
			ans.push_back(Item((1ll << (i - 1)) * 1ll * x, (1ll << (i - 1)) * 1ll * x, '+'));
		}
		ans.push_back(Item(x, (1ll << l) * x, '+'));
		ans.push_back(Item(x, (1ll << l) * x, '^'));
		ll f1 = (x + (1ll << l) * x);
		ll f2 = (x ^ ((1ll << l) * x));
		ans.push_back(Item(f1, f2, '^'));
		tmp = l + 1;
	}
	/*for (ll i = tmp; i < 55; i++) {
		ans.push_back(Item(1ll << i, 1ll << i, '+'));
	}*/
	while (x > 1) {
		if (x == (1ll << tmp) - 1) {
			ans.push_back(Item(x, x, '+'));
			ans.push_back(Item(x, 2 * x, '^'));
			ans.push_back(Item(x, x ^ (2 * x), '+'));
			ans.push_back(Item(x ^ (2 * x), x ^ (2 * x), '+'));
			ll f1 = 2 * (x ^ (2 * x));
			ll f2 = x + (x ^ (2 * x));
			ans.push_back(Item(f1, f2, '^'));
			ll cur = 2;
			for (int l = 1; l < 55; l++) {
				ans.push_back(Item(1ll << l, 1ll << l, '+'));
			}
			for (int l = 1; l < 55; l++) {
				if ((1ll << l) & x) {
					ans.push_back(Item(1ll << l, x, '^'));
					x = (x ^ (1ll << l));
				}
			}
			break;
		}
		ll f = x;
		while ((1ll << (tmp - 1)) & f) {
			ans.push_back(Item(f, f, '+'));
			f *= 2;
			ans.push_back(Item(f, (1ll << tmp), '^'));
			f = (f ^ (1ll << tmp));
		}
		ll l = 0;
		for (int i = 0; i < 55; i++) {
			if ((1ll << i) & f)
				l = i;
		}
		for (ll i = 1; i <= l; i++) {
			ans.push_back(Item((1ll << (i - 1)) * 1ll * f, (1ll << (i - 1)) * 1ll * f, '+'));
		}
		ll m = 0;
		for (ll i = 0; i <= l; i++) {
			if ((1ll << i) & f) {
				m = i;
				break;
			}
		}
		ans.push_back(Item(f, (1ll << (l - m)) * f, '+'));
		ans.push_back(Item(f, (1ll << (l - m)) * f, '^'));
		ll f1 = (f + (1ll << (l - m)) * f);
		ll f2 = (f ^ ((1ll << (l - m)) * f));
		//cout << f1 << " " << f2 << " " << f << endl;
		ans.push_back(Item(f1, f2, '^'));
		tmp = l + 1;
		for (ll i = tmp; i < 55; i++) {
			ans.push_back(Item(1ll << i, 1ll << i, '+'));
		}
		for (ll i = tmp; i < 55; i++) {
			if ((1ll << i) & x) {
				ans.push_back(Item(1ll << i, x, '^'));
				x = x ^ (1ll << i);
			}
		}
	}
	pr();
	return;
}
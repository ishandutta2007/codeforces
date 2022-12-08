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
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

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

const int N = 1e5;

void solve() {
	int m; cin >> m;
	vector<int> a;
	vector<pair<pair<ll, ll>, pair<ll, ll>>> kek;
	ll n = 0;
	while (m--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int x; cin >> x;
			if (a.size() < N) a.push_back(x);
			else kek.push_back({ {n, n}, {-1, x} });
			n++;
		}
		else {
			ll l, c; cin >> l >> c;
			while (c && a.size() < N) {
				for (int i = 0; i < l; i++) {
					a.push_back(a[i]);
				}
				n += l;
				c--;
			}
			if (c) kek.push_back({ { n,n + l * c - 1 }, { 0, l - 1 } });
			n += l * c;
		}
	}
	int q; cin >> q;
	while (q--) {
		ll x; cin >> x; x--;
		if (x < a.size()) cout << a[x] << " ";
		else {
			int h = upper_bound(all(kek), mp(mp(x, (ll)4e18), mp(1ll, 1ll))) - kek.begin() - 1;
			x -= kek[h].first.first;
			cout << a[x % (kek[h].second.second + 1)] << " ";
		}
	}
	return;
}
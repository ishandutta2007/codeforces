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
	ll a, b, c;
	Item() {}
	Item(ll a, ll b, ll c) : a(a), b(b), c(c) {}
};

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		ll s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		if (s % n) cout << -1 << endl;
		else {
			ll x = s / n;
			vector<Item> ans;
			for (int i = 1; i < n; i++) {
				ll d = ((i + 1) - a[i] % (i + 1)) % (i + 1);
				ans.push_back(Item(1, i + 1, d));
				a[i] += d;
				a[0] -= d;
				ans.push_back(Item(i + 1, 1, a[i] / (i + 1)));
				a[0] += a[i];
				a[i] = 0;
			}
			for (int i = 1; i < n; i++) {
				ans.push_back(Item(1, i + 1, x));
			}
			cout << ans.size() << endl;
			for (Item i : ans)
				cout << i.a << " " << i.b << " " << i.c << endl;
		}
	}
	return;
}
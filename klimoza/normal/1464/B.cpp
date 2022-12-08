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

ll get(string s, ll x, ll y) {
	int n = s.size();
	ll c0 = 0;
	ll c1 = 0;
	ll ans = inf;
	ll cur = 0;
	vector<pair<ll, ll>> kek(n + 1, mp(0, 0));
	for (int i = n - 1; i >= 0; i--) {
		kek[i].first = kek[i + 1].first;
		kek[i].second = kek[i + 1].second;
		if (s[i] == '1')
			kek[i].first++;
		else
			kek[i].second++;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			cur += c0 * 1ll * x;
			c1++;
		}
		else {
			cur += c1 * 1ll * y;
			c0++;
		}
	}
	ans = cur;
	c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			c0++;
		else if (s[i] == '1')
			c1++;
		else {
			cur -= (kek[i].first * 1ll * x + c1 * 1ll * y);
			cur += (c0 * 1ll * x + (kek[i].second - 1) * 1ll * y);
			ans = min(ans, cur);
			c1++;
		}
	}
	return ans;
}

void solve() {
	string s; cin >> s;
	int n = s.size();
	ll x, y; cin >> x >> y;
	ll ans = get(s, x, y);
	reverse(all(s));
	ans = min(ans, get(s, y, x));
	cout << ans << endl;
	return;
}
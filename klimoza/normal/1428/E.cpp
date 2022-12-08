
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

#define int long long

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

ll sq(ll a) {
	return a * a;
}

ll d(ll a, ll c) {
	ll ans = 0;
	ll x = a % c;
	ans += x * sq((a + c - 1) / c);
	ans += (c - x) * sq((a / c));
	return ans;
}

ll diff(ll a, ll c1, ll c2) {
	return d(a, c1) - d(a, c2);
}

void solve() {
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	k -= n;
	vector<int> c(n);
	set<pair<ll, int>> mem;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[i] = 1;
		mem.insert({ diff(a[i], 1, 2), i });
	}
	while (k) {
		k--;
		auto v = *mem.rbegin();
		mem.erase(mem.find(v));
		c[v.second]++;
		v.first = diff(a[v.second], c[v.second], c[v.second] + 1);
		mem.insert(v);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += d(a[i], c[i]);
	}
	cout << ans << endl;
	return;
}
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

const int L = 60;

ll cnt[L];

ll add(ll a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		fill(cnt, cnt + L, 0);
		int n; cin >> n;
		vector<ll> x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			for (int j = 0; j < L; j++)
				if ((1ll << j) & x[i])
					cnt[j]++;
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll s1 = 0, s2 = 0;
			for (int j = 0; j < L; j++) {
				if ((1ll << j) & x[i]) {
					s1 = add(s1, mul((1ll << j) % mod, cnt[j]));
					s2 = add(s2, mul((1ll << j) % mod, n));
				}
				else {
					s2 = add(s2, mul((1ll << j) % mod, cnt[j]));
				}
			}
			ans = add(ans, mul(s1, s2));
		}
		cout << ans << endl;
	}
	return;
}
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

const int N = 1e6 + 1;
ll lp[N + 1];
vector<ll> pr;

void sieve() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

void solve() {
	sieve();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<ll> kek;
		for (int i = 0; i < n; i++) {
			ll cur = -1;
			ll cnt = 0;
			ll g = 1;
			ll x = a[i];
			while (x > 1) {
				if (cur == lp[x]) {
					cnt++;
				}
				else {
					if (cnt & 1)
						g *= cur;
					cur = lp[x];
					cnt = 1;
				}
				x = x / lp[x];
			}
			if (cnt & 1)
				g *= cur;
			kek.push_back(g);
		}
		sort(all(kek));
		vector<pair<ll, int>> mem;
		for (ll i : kek) {
			if (mem.empty() || mem.back().first != i)
				mem.push_back(mp(i, 1));
			else
				mem.back().second++;
		}
		ll ans = 0;
		for (auto u : mem)
			ans = max(ans, (ll)u.second);
		ll ans1 = 0;
		ll s = 0;
		for (auto u : mem) {
			if (u.first != 1 && (u.second & 1))
				ans1 = max(ans1, (ll)u.second);
			else
				s += u.second;
		}
		ans1 = max(ans1, s);
		int q; cin >> q;
		while (q--) {
			ll w; cin >> w;
			if (!w)
				cout << ans << endl;
			else
				cout << ans1 << endl;
		}
	}
	return;
}
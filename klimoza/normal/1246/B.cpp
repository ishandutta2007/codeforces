#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

ll bp(ll n, ll k, ll m) {
	ll res = 1;
	while (k) {
		if (k & 1) {
			if (res > m / n) return -1;
			res *= n;
		}
		k >>= 1;
		if (k && n > sqrt(m)) return -1;
		n *= n;
	}
	return res;
}

const int N = 1e5 + 8;

ll cnt[N];
ll was[N];

void solve() {
	ll n, k; cin >> n >> k;
	vector<int> a(n);
	fill(cnt, cnt + N, 0);
	fill(was, was + N, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	ll ans = 0;
	if (k != 2) {
		for (ll x = 1; x <= 1e5; x++) {
			ll t = bp(x, k, 1e10);
			if (t == -1) break;
			//cout << t << endl;
			for (ll i = 1; i <= sqrt(t); i++) {
				if (t % i) continue;
				ll f = t / i;
				if (f > 1e5) continue;
				if (i == f) ans += cnt[i] * (cnt[i] - 1) / 2;
				else ans += cnt[i] * cnt[f];
			}
		}
	}
	else {
		ll p[200];
		for (ll x = 1; x <= 1e5; x++) {
			int sz = 0;
			ll g = x * x;
			for (ll i = 2; i <= sqrt(x); i++) {
				if (x % i) continue;
				p[sz++] = i;
				if (i * i != x) p[sz++] = x / i;
			}
			p[sz++] = 1;
			p[sz++] = x;
			for (int i = 0; i < sz; i++) {
				for (int j = 0; j < sz; j++) {
					ll t = p[i] * p[j];
					if (g % t == 0) {
						if (t > 1e5 || (g / t) > 1e5) continue;
						if (was[t] == x) continue;
						if (t * t == g) ans += cnt[t] * (cnt[t] - 1) / 2;
						else ans += cnt[t] * cnt[g / t];
						was[t] = x;
						was[g / t] = x;
					}
				}
			}
		}
	}
	cout << ans << endl;
}
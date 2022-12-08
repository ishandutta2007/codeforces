#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

mt19937 mrand(random_device{} ());

const int N = 2e5 + 7;

ll f[N];
ll m[N];
ll s[N];

ll ans = 0;

ll binpow(ll a, ll k) {
	int ans = 1;
	while (k) {
		if (k & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		k >>= 1;
	}
	return ans;
}

ll del(ll a, ll b) {
	return (a * binpow(b, mod - 2)) % mod;
}

ll C(int n, int k) {
	return del(del(f[n], f[n - k]), f[k]);
}

void buildFac();
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	#endif
	
	buildFac();
	ll n, T;
	cin >> n >> T;
	vector<ll> t(n);
	for (ll& i : t) cin >> i;
	vector<ll> pref(n, t[0]);
	for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + t[i];
	for (ll i = 0; i < n; i++) m[i] = min(i + 1, T - pref[i]);
	for (ll i = 0; i < n; i++) {
		if (pref[i] > T) break;
		if (pref[i] + (i + 1) <= T) { 
			ans += 1; 
			continue;
		}
		if (i == 0 || pref[i - 1] + i <= T) {
			for (int k = 0; k <= m[i]; k++) {
				s[i] = (s[i] + C(i + 1, k)) % mod;
			}
		}
		else {
			s[i] = 2 * s[i - 1];
			s[i] = (s[i] + C(i, m[i - 1] + 1)) % mod;
			s[i] -= C(i + 1, m[i - 1] + 1);
			s[i] = (s[i] + mod) % mod;
			if (i == 0 || m[i - 1] + 1 == m[i]) {}
			else {
				while (m[i - 1] != m[i]) {
					s[i] -= C(i + 1, m[i - 1]--);
					s[i] = (s[i] + mod) % mod;
				}
			}
			s[i] %= mod;
		}
		//cout << i << endl << s[i] << " " << m[i] << endl;
		ans += del(s[i], binpow(2, i + 1));
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

void buildFac() {
	f[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = (f[i - 1] * i) % mod;
	}
}
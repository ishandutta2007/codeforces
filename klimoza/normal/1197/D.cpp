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

#define all(v) (v).begin(), (v).end()
#define size(v) (v).size()

using namespace std;
typedef long long ll;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

void solve();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);

	solve();
	return 0;
}



ll stupid(ll n, ll m, ll k, vector<ll> a) {
	vector<ll> pref(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = i; j < n; j++) {
			ans = max(ans, pref[j + 1] - pref[i] - k * ((j - i + m) / m));
		//	cout << ans << " " << i << " " << j << endl;
		}
	}
	return ans;
}

ll smart(ll n, ll m, ll k, vector<ll> a) {
	vector<ll> pref(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}
	ll ans = max(a[0] - k, (ll)0);
	vector<ll> mini(m, inf0);
	mini[0] = 0;
	for (ll i = 1; i < n; i++) {
		ll ff = m;
		if (i < m) ff = i;
		ll cur = 0;
		ans = max(ans, a[i] - k);
		//cout << i << endl;
		for (ll j = 0; j < ff; j++) {
			cur = pref[i + 1] - k * ((i) / m) - mini[j];
			if (j <= (i % m)) cur -= k;
			//cout << cur << " " << j << endl;
			ans = max(ans, cur);
		}
		//cout << i << " " << ans << " " << cur << " "  << endl;
		mini[i % m] = min(mini[i % m], pref[i] - k * ((i) / m));
	}
	cout << ans << endl;
	return ans;
}

void stress() {
	while (true) {
		ll n = mrand() % 5 + 1;
		ll m = mrand() % 10 + 1;
		ll k = mrand() % 20 + 1;
		vector<ll> a(n);
		//cout << "ek\n";
		for (ll& i : a) i = (rand() % 100) - 49;
		if (smart(n, m, k, a) != stupid(n, m, k, a)) {
			cout << smart(n, m, k, a) << " " << stupid(n, m, k, a) << endl;
			cout << n << " " << m << " " << k << endl;
			for (ll i : a) cout << i << " ";
			cout << endl;
			return;
		}
	}
}

void solve() {
	//stress();
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	for (ll &i : a)cin >> i;
	smart(n, m, k, a);
}
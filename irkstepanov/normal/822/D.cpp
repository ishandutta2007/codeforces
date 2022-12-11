#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int nmax = 5e6 + 100;

int mind[nmax];
ll f[nmax];

const ll mod = 1e9 + 7;

void add(ll& a, ll b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void mul(ll& a, ll b) {
	a *= b;
	if (a >= mod) {
		a %= mod;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	for (int i = 2; i < nmax; ++i) {
		mind[i] = i;
	}

	for (int i = 2; i < nmax; ++i) {
		if (mind[i] == i) {
			for (int j = 2 * i; j < nmax; j += i) {
				mind[j] = min(mind[j], i);
			}
		}
	}

	f[1] = 0;
	for (int n = 2; n < nmax; ++n) {
		int x = mind[n];
		f[n] = f[n / x] + ll(n) * (ll(x) - 1) / 2;
	}

	ll t;
	int l, r;
	cin >> t >> l >> r;
	ll ans = 0;
	ll deg = 1;

	for (int i = l; i <= r; ++i) {
		ll val = f[i] % mod;
		mul(val, deg);
		add(ans, val);
		mul(deg, t);
	}

	cout << ans << "\n";

}
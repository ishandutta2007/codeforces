#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

// if k >= n, answer = 2^n

// number of things with x gray edges:
// n edges: 1
// n-1 edges: 2
// n-2 edges: 4
// n-3 edges: 8
// ...

// n = 3
// 3 edges: 1 // (3 choose 3)
// 2 edges: 3 // (3 choose 2)
// 1 edge:  3 // (3 choose 1)
// 0 edges: 1 // (3 choose 0)

// number of things we can disqualify:
// (n choose n) + (n choose n-1) + ... + (n choose k+1)

constexpr ll mod = 1e9 + 7;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll modinv(ll x) {
	return modpow(x, mod-2);
}

#define MAXN 100'010

ll facs[MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	facs[0] = 1;
	rep(i, 1, MAXN) {
		facs[i] = facs[i-1]*i;
		facs[i] %= mod;
	}

	ll n, k;
	cin >> n >> k;
	ll subs = 0;

	for (ll i = n; i > k; i--) {
		// (n choose i)
		ll binom = facs[n] * modinv(facs[i]);
		binom %= mod;
		binom *= modinv(facs[n-i]);
		binom %= mod;
		subs += binom;
		subs %= mod;
	}

	ll twon = 1;
	rep(i, 0, n) {
		twon *= 2;
		twon %= mod;
	}
	ll out = twon - subs;
	out %= mod;
	if (out < 0) out += mod;
	cout << out << endl;
}
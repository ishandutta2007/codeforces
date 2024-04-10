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

constexpr ll mod = 998244353;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll modinv(ll x) {
	return modpow(x, mod-2);
}

#define MAXN 300'100

ll fac[MAXN];

ll choose(ll x, ll y) {
	ll out = fac[x] * modinv(fac[y]);
	out %= mod;
	out *= modinv(fac[x-y]);
	out %= mod;
	return out;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	fac[0] = 1;
	rep(i, 1, MAXN) {
		fac[i] = i*fac[i-1];
		fac[i] %= mod;
	}

	int t;
	cin >> t;
	while (t--) {

	ll n;
	cin >> n;

	ll out = 0;
	ll prog = 1;
	ll prog2 = 1;
	rep(s, 0, n+1) {
		if (s > 1) {
			ll prog3 = prog + (s-1)*prog2;
			prog3 %= mod;
			prog2 = prog;
			prog = prog3;
		}
		if ((n - s) % 2 != 0) continue;

		int d = (n - s) / 2;
		if (d % 2 != 0) continue;
		d /= 2;

		ll med = fac[2*d] * modinv(fac[d]);
		med %= mod;
		med *= choose(2*d+s, 2*d);
		med %= mod;

		
		


		med *= prog;
		med %= mod;
		out += med;
		out %= mod;
		//cout << s << ' ' << med << endl;
	}
	cout << out << '\n';
	}
}
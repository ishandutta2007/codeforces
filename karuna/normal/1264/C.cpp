#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
ll N, Q;
ll A[200020], acc[200020], pfx[200020];
set<ll> st;

ll mypow(ll a, ll x) {
	ll ret = 1;
	while (x) {
		if (x&1) ret = ret*a%mod;
		a = a*a%mod; x/=2;
	}
	return ret;
}

ll inv(ll a) {
	return mypow(a, mod-2);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> Q;
	for (ll i=2; i<=N+1; i++) {
		cin >> A[i];
		A[i] = A[i]*inv(100)%mod;
	}

	pfx[1] = acc[1] = 1;
	for (ll i=2; i<=N+1; i++) {
		acc[i] = acc[i-1]*A[i]%mod;
		pfx[i] = (pfx[i-1] + acc[i])%mod;
	}

	st.insert(2);
	st.insert(N+2);

	ll ans = pfx[N] * inv(acc[N+1]) % mod;

	for (ll i=0; i<Q; i++) {
		ll x; cin >> x; x++;

		if (st.find(x) == st.end()) {
			st.insert(x);
			auto it = st.find(x);
			ll p = *prev(it), n = *next(it);

			ans = (ans+mod - (pfx[n-2]+mod-pfx[p-2])%mod * inv(acc[n-1]) % mod) % mod;

			ans = (ans + (pfx[x-2]+mod-pfx[p-2])%mod * inv(acc[x-1]) % mod) % mod;
			ans = (ans + (pfx[n-2]+mod-pfx[x-2])%mod * inv(acc[n-1]) % mod) % mod;

		}
		else {
			auto it = st.find(x);
			ll p = *prev(it), n = *next(it);
			st.erase(x);

			ans = (ans+mod - (pfx[x-2]+mod-pfx[p-2])%mod * inv(acc[x-1]) % mod) % mod;
			ans = (ans+mod - (pfx[n-2]+mod-pfx[x-2])%mod * inv(acc[n-1]) % mod) % mod;
			ans = (ans + (pfx[n-2]+mod-pfx[p-2])%mod * inv(acc[n-1]) % mod) % mod;
		}

		cout << ans << '\n';
	}
}
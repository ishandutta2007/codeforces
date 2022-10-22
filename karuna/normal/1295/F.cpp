#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
ll N;
ll L[51], R[51], dp[51][103], pfx[51][103];

ll mypow(ll a, ll x) {
	ll ret = 1;
	while (x) {
		if (x&1) ret = ret*a%mod;
		a = a*a%mod; x/=2;
	}
	return ret;
}
ll inv(ll a) { return mypow(a, mod-2); }
ll func(ll n, ll k) {
	ll ret = 1, t = 1;
	for (ll i=k; i<k+n; i++) ret = ret*i%mod;
	for (ll i=1; i<=n; i++) t = t*i%mod;
	return ret * inv(t)%mod * inv(mypow(k, n))%mod;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;

	vector<ll> v;
	for (ll i=1; i<=N; i++) {
		cin >> L[i] >> R[i];
		v.push_back(L[i]);
		v.push_back(R[i]+1);
	}
	v.push_back(0);
	v.push_back(mod-1);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (ll i=1; i<=N; i++) {
		L[i] = lower_bound(v.begin(), v.end(), L[i]) - v.begin();
		R[i] = lower_bound(v.begin(), v.end(), R[i]+1) - v.begin()-1;
	}

	ll K = v.size();

	for (ll i=0; i<K; i++) pfx[0][i] = 1;
	for (ll i=R[1]; i>=L[1]; i--) {
		ll len = v[R[1]+1] - v[L[1]];
		ll t = v[i+1] - v[i];
		dp[1][i] = t * inv(len)%mod;
		pfx[1][i] = (pfx[1][i+1] + dp[1][i])%mod;
	}
	for (ll i=0; i<L[1]; i++) pfx[1][i] = 1;


	for (ll i=2; i<=N; i++) {
		for (ll j=K-2; j>=0; j--) {
			ll k = v[j+1] - v[j], x = 1;
			for (ll a=i; a>=1; a--) {
				if (j < L[a] || j > R[a]) break;
				ll Alen = v[R[a]+1] - v[L[a]];
				x = x * k%mod * inv(Alen)%mod;

				dp[i][j] = (dp[i][j] + pfx[a-1][j+1] * x%mod * func(i-a+1LL, k)%mod)%mod;
			}
			pfx[i][j] = (pfx[i][j+1] + dp[i][j])%mod;
		}
	}

	ll ans = 0;
	for (ll i=0; i<K; i++) ans = (ans + dp[N][i])%mod;

	cout << ans%mod;
}
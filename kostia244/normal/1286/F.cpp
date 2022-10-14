#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20;
ll n, sm[1<<N], pop[1<<N], f[1<<N], g[1<<N], og[1<<N];
template<int inv>
void conv(ll *F) {
	for(int b = 1; b < 1<<n; b*=2)
	for(int i = 0; i < 1<<n; i++) {
		if(i&b) {
			if(inv)
				F[i] -= F[i^b];
			else
				F[i] += F[i^b];
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	for(ll t, i = 0; i < n; i++) {
		cin >> t;
		for(int j = 0; j < 1<<n; j++) if((j>>i)&1)
			sm[j] += t;
	}
	//sum (n choose i) * 2^(0.5i)
	for(int msk = 0; msk < 1<<n; msk++) {
		pop[msk] = __builtin_popcount(msk);
		int l = 0;
		while(2*pop[msk&l] < pop[msk])
			l = 2*l+1;
		l &= msk;
		int r = msk^l;
		vector<ll> can[2];
		#define P(x) ((x)&1)
		for(int z = (l-1)&l; z; z = (z-1)&l)
			can[P(sm[z]-sm[l^z])].push_back(sm[z]-sm[l^z]);
		for(auto &i : can)
			sort(i.begin(), i.end());
		ll ans = 0;
		for(int z = r; ; z = (z-1)&r) {
			ll cur = sm[z]-sm[z^r];
			ll R = P(cur)^P(pop[msk]-1);
			auto it = lower_bound(can[R].begin(), can[R].end(), -cur);//at least 0
			if(it != can[R].end()) {
				ans |= *it+cur < pop[msk];
			}
			if(z) {
				ans |= abs(cur-sm[l]) < pop[msk] && P(cur-sm[l]) == P(pop[msk]-1);
			}
			if(z^r) {
				ans |= abs(cur+sm[l]) < pop[msk] && P(cur+sm[l]) == P(pop[msk]-1);
			}
			if(!z) break;
		}
		f[msk] = ans;
		if(pop[msk] == 1 && sm[msk] == 0)
			f[msk] = 1;
	}
	int ans = n, ful = (1<<n)-1;
	// g[0] = 1;
	// conv<0>(f);
	// for(int i = 1; i <= n; i++) {
		// conv<0>(g);
		// for(int msk = 0; msk < 1<<n; msk++)
			// g[msk] = g[msk]*f[msk];
		// conv<1>(g);
		// for(int msk = 0; msk < 1<<n; msk++) {
			// g[msk] = !!g[msk];
			// if(g[msk] != og[msk]) {
				// ans = min<ll>(ans, n-i+pop[ful^msk]);
			// }
			// og[msk] = g[msk];
		// }
	// }
	//mobius transform would be too slow here if I account for non-intersecting masks
	for(int msk = 0; msk < 1<<n; msk++) {
		for(int z = msk; z; z = (z-1)&msk)
			f[msk] = max(f[msk], f[z]+f[msk^z]);
		ans = min<ll>(ans, n-f[msk]+pop[ful^msk]);
	}
	cout << ans << '\n';
}
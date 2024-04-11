#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll d, q;
map<ll, ll> ans;
void setup() {
	vi divs;
	for(ll i = 1; i*i <= d; i++) {
		if(d%i) continue;
		if(i>1) divs.pb(i);
		if(i*i!=d) divs.pb(d/i);
	}
	sort(all(divs));
	ans[1] = 1;
	for(auto i : divs) {
		ll ti = i;
		for(ll x = 2; x * x <= ti; x++) {
			if(ti%x) continue;
			while(ti%x == 0) ti/=x;
			(ans[i] += ans[i/x])%=mod;
		}
		if(ti>1) (ans[i] += ans[i/ti])%=mod;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> d;
	setup();
	ll a, b;
	cin >> q;
	while(q--) {
		cin >> a >> b;
		ll g= __gcd(a, b);
		a/=g, b/=g;
		cout << ans[a]*1ll*ans[b]%mod << '\n';
	}
	return 0;
}
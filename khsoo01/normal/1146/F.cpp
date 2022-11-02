#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353, N = 200005;

ll n, dt[N][2];

vector<ll> adj[N];

ll calc (ll X, ll Y) {
	if(!Y) return 1;
	ll R = calc(X, Y/2);
	R = R * R % mod;
	if(Y % 2) R = R * X % mod;
	return R;
}

void solve (ll I) {
	if(adj[I].size() == 0) {
		dt[I][0] = dt[I][1] = 1;
		return;
	}
	ll A = 1, B = 1;
	for(auto &T : adj[I]) {
		solve(T);
		A = (A * (dt[T][0] + dt[T][1])) % mod;
		B = B * dt[T][0] % mod;
	}
	dt[I][0] = dt[I][1] = A;
	dt[I][1] = (dt[I][1] + mod - B) % mod;
	for(auto &T : adj[I]) {
		dt[I][0] = (dt[I][0] + mod - B * calc(dt[T][0], mod-2) % mod * dt[T][1] % mod) % mod;
	}
}

int main()
{
	scanf("%lld",&n);
	for(ll i=2;i<=n;i++) {
		ll T;
		scanf("%lld",&T);
		adj[T].push_back(i);
	}
	solve(1);
	printf("%lld\n", dt[1][0]);
}
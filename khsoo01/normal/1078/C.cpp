#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 300005, M = 998244353;

ll n, dt[N][3];
vector<ll> adj[N];

ll calc (ll A, ll B) {
	if(!B) return 1;
	ll R = calc(A, B/2);
	R = (R * R) % M;
	if(B&1) R = (R * A) % M;
	return R;
}

void solve (ll C, ll P) {
	ll A = 1, B = 1;
	for(auto &T : adj[C]) {
		if(T == P) continue;
		solve(T, C);
		A = (A * (2*dt[T][0] + dt[T][2])) % M;
		B = (B * (dt[T][0] + dt[T][2])) % M;
	}
	dt[C][1] = A;
	dt[C][2] = B;
	for(auto &T : adj[C]) {
		if(T == P) continue;
		dt[C][0] = (dt[C][0] + A * calc(2*dt[T][0] + dt[T][2], M - 2) % M * dt[T][1] % M) % M;
	}
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<n;i++) {
		ll A, B;
		scanf("%lld%lld",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	solve(1, 0);
	printf("%lld\n", (dt[1][0] + dt[1][2]) % M);
}
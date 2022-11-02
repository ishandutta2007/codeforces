#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

ll n, m, f, e, v, q;

vector<ll> a, b;

ll solve (vector<ll> &X, ll S, ll E) {
	if(X.empty()) return inf;
	ll T = lower_bound(X.begin(), X.end(), S) - X.begin();
	if(T != X.size() && X[T] <= E) return E-S;
	ll ret = inf;
	if(T != X.size()) ret = min(ret, E-S + 2*(X[T]-E));
	if(T != 0) ret = min(ret, E-S + 2*(S-X[T-1]));
	return ret;
}

int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&m,&f,&e,&v);
	for(ll i=1;i<=f;i++) {
		ll T;
		scanf("%lld",&T);
		a.push_back(T);
	}
	for(ll i=1;i<=e;i++) {
		ll T;
		scanf("%lld",&T);
		b.push_back(T);
	}
	scanf("%lld",&q);
	while(q--) {
		ll A, B, C, D;
		scanf("%lld%lld%lld%lld",&B,&A,&D,&C);
		if(A > C) swap(A, C);
		if(B > D) swap(B, D);
		if(B == D) printf("%lld\n", C-A);
		else {
			ll T = inf;
			T = min(T, solve(a, A, C) + (D-B));
			T = min(T, solve(b, A, C) + (D-B+v-1)/v);
			printf("%lld\n",T);
		}
	}
}
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll N = 300005, G = 19, inf = 4e18;

ll n, q, v[N], dep[N], par[G][N], cost[G][N][2][2];

vector<pair<ll, pll> > adj[N];

void downcalc (ll C, ll P) {
	for(auto &X : adj[C]) {
		ll T = X.X, A, B;
		tie(A, B) = X.Y;
		if(T == P) continue;
		downcalc(T, C);
		v[C] = min(v[C], v[T] + A + B);
	}
}

void upcalc (ll C, ll P) {
	for(auto &X : adj[C]) {
		ll T = X.X, A, B;
		tie(A, B) = X.Y;
		if(T == P) continue;
		par[0][T] = C;
		dep[T] = dep[C] + 1;
		v[T] = min(v[T], v[C] + A + B);
		cost[0][T][0][0] = min(v[C] + v[T] + B, A);
		cost[0][T][0][1] = min(A + v[C], B + v[T]);
		cost[0][T][1][0] = min(A + v[T], B + v[C]);
		cost[0][T][1][1] = min(v[C] + v[T] + A, B);
		upcalc(T, C);
	}
}

ll getlca (ll A, ll B) {
	if(dep[A] < dep[B]) swap(A, B);
	for(ll i=G;i--;) {
		if(dep[A] - dep[B] >= (1<<i)) A = par[i][A];
	}
	if(A == B) return A;
	for(ll i=G;i--;) {
		if(par[i][A] != par[i][B]) {
			A = par[i][A];
			B = par[i][B];
		}
	}
	return par[0][A];
}

pll get (ll X, ll Y, ll Z) {
	ll V[2];
	V[Y] = 0;
	V[Y^1] = v[X];
	for(ll i=G;i--;) {
		if(dep[X] - dep[Z] >= (1<<i)) {
			ll W[2] = {inf, inf};
			for(ll k1=0;k1<2;k1++) for(ll k2=0;k2<2;k2++) {
				W[k2] = min(W[k2], V[k1] + cost[i][X][k1][k2]);
			}
			V[0] = W[0];
			V[1] = W[1];
			X = par[i][X];
		}
	}
	return {V[0], V[1]};
}

void solve () {
	ll AX, AY, BX, BY, C;
	scanf("%lld%lld",&AX,&BX);
	AY = (AX-1)%2;
	AX = (AX-AY+1)/2;
	BY = (BX-1)%2;
	BX = (BX-BY+1)/2;
	C = getlca(AX, BX);
	pll AA = get(AX, AY, C), BB = get(BX, BY, C);
	printf("%lld\n", min(AA.X+BB.X, AA.Y+BB.Y));
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&v[i]);
	}
	for(ll i=1;i<n;i++) {
		ll A, B, C, D;
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		adj[A].push_back({B, {C, D}});
		adj[B].push_back({A, {C, D}});
	}
	downcalc(1, 0);
	upcalc(1, 0);
	for(ll i=1;i<G;i++) {
		for(ll j=1;j<=n;j++) {
			par[i][j] = par[i-1][par[i-1][j]];
			for(int k1=0;k1<2;k1++) for(int k2=0;k2<2;k2++) {
				ll T = inf;
				for(int k3=0;k3<2;k3++) {
					T = min(T, cost[i-1][j][k1][k3] + cost[i-1][par[i-1][j]][k3][k2]);
				}
				cost[i][j][k1][k2] = T;
			}
		}
	}
	scanf("%lld",&q);
	while(q--) solve();
}
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll N = 500005, L = (1<<19), inf = 1e18;

ll n, q, s[N], e[N], d[N], ans[N];
vector<pll> adj[N];
vector<pair<ll, pll> > swp[N];

struct segtree {
	ll v[2*L], l[2*L];
	void lazydown (ll P) {
		v[2*P] += l[P];
		v[2*P+1] += l[P];
		l[2*P] += l[P];
		l[2*P+1] += l[P];
		l[P] = 0;
	}
	void upd (ll S, ll E, ll X, ll SS = 0, ll SE = L-1, ll P = 1) {
		if(S <= SS && SE <= E) {
			v[P] += X;
			l[P] += X;
			return;
		}
		if(E < SS || SE < S) return;
		lazydown(P);
		ll M = (SS+SE)/2;
		upd(S, E, X, SS, M, 2*P);
		upd(S, E, X, M+1, SE, 2*P+1);
		v[P] = min(v[2*P], v[2*P+1]);
	}
	ll get (ll S, ll E, ll SS = 0, ll SE = L-1, ll P = 1) {
		if(S <= SS && SE <= E) return v[P];
		if(E < SS || SE < S) return inf;
		lazydown(P);
		ll M = (SS+SE)/2;
		return min(get(S, E, SS, M, 2*P), get(S, E, M+1, SE, 2*P+1));
	}
} seg;

void calc (ll I) {
	s[I] = e[I] = I;
	for(auto &T : adj[I]) {
		ll A, B;
		tie(A, B) = T;
		d[A] = d[I] + B;
		calc(A);
		e[I] = max(e[I], e[A]);
	}
}

void solve (ll I) {
	for(auto &T : swp[I]) {
		ll X = T.X, A, B;
		tie(A, B) = T.Y;
		ans[X] = seg.get(A, B);
	}
	for(auto &T : adj[I]) {
		ll A, B;
		tie(A, B) = T;
		seg.upd(1, n, B);
		seg.upd(s[A], e[A], -2*B);
		solve(A);
		seg.upd(1, n, -B);
		seg.upd(s[A], e[A], 2*B);
	}
}

int main()
{
	scanf("%lld%lld",&n,&q);
	for(ll i=2;i<=n;i++) {
		ll A, B;
		scanf("%lld%lld",&A,&B);
		adj[A].push_back({i, B});
	}
	calc(1);
	for(ll i=1;i<=n;i++) {
		if(s[i] != e[i]) seg.upd(i, i, inf);
		else seg.upd(i, i, d[i]);
	}
	for(ll i=1;i<=q;i++) {
		ll I, A, B;
		scanf("%lld%lld%lld",&I,&A,&B);
		swp[I].push_back({i, {A, B}});
	}
	solve(1);
	for(ll i=1;i<=q;i++) {
		printf("%lld\n", ans[i]);
	}
}
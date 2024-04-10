#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin>>x;
#define F(i,l, r) for (ll i=(l); i<(r); ++i)
#define all(x) begin(x), end(x)
#define K first
#define V second

#define NN 110

vector<ll> edges[NN];
ll mark[NN], dep[NN], par[NN];

ll best = 1;
ll k;
void deep(ll u, ll d) {
	dep[u] = d;
	if (dep[u]>dep[best] && dep[u]<=k-1) {
		best = u;
	}
	for (auto v:edges[u])
		deep(v, d+1);
}
vector<ll> path;

ll a;
void dfs(ll u) {
	if(!mark[u]) a--;
	for (auto v:edges[u]) {
		if (!mark[v] && a) {
			path.push_back(v);
			dfs(v);
			path.push_back(u);
		}
	}
	for (auto v:edges[u]) {
		if (mark[v]) {
			path.push_back(v);
			dfs(v);
		}
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T; cin>>T;
	while (T--) {
		ll n; cin>>n>>k;
		for (ll i=1; i<=n; ++i) {
			edges[i].clear();
			mark[i] = 0, dep[i]=0;
		}
		path.clear();
		best = 1;
		for (ll i=2; i<=n; ++i) {
			ll p; cin>>p;
			edges[p].push_back(i);
			par[i]=p;
		}
		deep(1, 0);
		ll cur = best;
		while (cur!=0) {
			mark[cur] = 1;
			cur = par[cur];
		}
		a = k-dep[best]-1;
		path.push_back(1);
		dfs(1);
		cout<<path.size()-1<<'\n';
		for (auto o:path) cout<<o<<' ';
		cout<<endl;
	}
}
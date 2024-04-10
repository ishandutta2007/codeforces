#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin>>x;
#define F(i, l, r) for (ll i=l i<(r); ++i)
#define all(a) begin(a), end(a)
#define K first
#define V second

#define NN 1000010

vl graph[NN], rGraph[NN], ord;
ll scc[NN], r[NN];
vl s[NN];
bool used[NN];

void dfs1(ll i) {
	used[i] = true;
	for (ll j:graph[i]) if (!used[j]) dfs1(j);
	ord.push_back(i);
}

void dfs2(ll i, ll c) {
	scc[i]=c;
	for (ll j:rGraph[i]) if (!scc[j]) dfs2(j, c);
}

void imply(ll a, ll b) {
	graph[a].push_back(b);
	graph[b^1].push_back(a^1);

	rGraph[b].push_back(a);
	rGraph[a^1].push_back(b^1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m; cin>>n>>m;
	for (ll i=0; i<n; ++i) {
		cin>>r[i];
	}
	for (ll i=0; i<m; ++i) {
		ll x; cin>>x;
		for (ll j=0; j<x; ++j) {
			ll u; cin>>u; --u;
			s[u].push_back(i);
		}
	}
	for (ll i=0; i<n; ++i) {
		if (r[i]==0) {
			imply(2*s[i][0], 2*s[i][1]+1);
			imply(2*s[i][0]+1, 2*s[i][1]);
		} else {
			imply(2*s[i][0], 2*s[i][1]);
			imply(2*s[i][1], 2*s[i][0]);
		}
	}

	n = 2*m;
	for (ll i=0; i<n; ++i) if (!used[i]) dfs1(i);
	ll c = 1;
	reverse(all(ord));
	for (ll i:ord) if (!scc[i]) dfs2(i, c++);

	for (ll i=0; i<m; ++i) if (scc[2*i]==scc[2*i+1]) {
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";

}
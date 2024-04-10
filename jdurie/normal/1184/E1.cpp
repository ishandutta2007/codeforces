#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

tuple<ld, ll, ll> edges[1000010];
tuple<ld, ll, ll> edge[1000010];
ll parent[100010];
ll m, n;

ll find(ll a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

ll verify(ll c) {
	memcpy(edge, edges, (sizeof edges[0])*m);
	for (ll i=1;i<=n;++i) parent[i]=i;
	ll left=n-1;
	ld temp = c-0.01;
	get<0>(edge[0]) = c-0.01;
	sort(edge, edge+m);

	ll i=0;
	while (left) {
		if (find(get<1>(edge[i]))!=find(get<2>(edge[i]))) {
			parent[find(get<1>(edge[i]))]=find(get<2>(edge[i]));
			left--;
			if (get<0>(edge[i])==temp) {
				return true;
			}
		}
		i++;
	}
	return false;
}

ll bsearch(ll l, ll r) {
	if (l==r) return l;
	ll m = (l+r+1)/2;
	if (verify(m)) 
					return bsearch(m, r);
	return bsearch(l, m-1);
}

int main() {
				  ios_base::sync_with_stdio(false);
					  cin.tie(NULL);

	cin>>n>>m;
	for (ll i=0;i<m;++i) {
		ll a, b, e;
		cin>>a>>b>>e;
		edges[i]={e, a, b};
	}
	cout<<bsearch(0, 1000000000)<<endl;
}
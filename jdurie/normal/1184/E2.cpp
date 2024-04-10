#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

tuple<int, int, int, int> edges[1000010];
ll parent[100010];
set<int> sets[100010];

ll n, m;

vector<pair<ll, ll> > ans;

ll find(ll a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

int main() {
				  ios_base::sync_with_stdio(false);
					  cin.tie(NULL);

	cin>>n>>m;
	for (ll i=0;i<m;++i) {
		ll a, b, e;
		cin>>a>>b>>e;
		edges[i] = {e, a, b, i};
		sets[a].insert(i);
		sets[b].insert(i);
	}

	for (ll i=1;i<=n;++i) parent[i]=i;

	sort(edges, edges+m);
	ll left = n-1;
	ll i=0;
	while (left) {
		ll a = find(get<1>(edges[i]));
		ll b = find(get<2>(edges[i]));
		if (a!=b) {
			if (sets[a].size()>sets[b].size()) swap(a,b);
			for (ll q:sets[a]) {
				if (sets[b].count(q)) {
					if (q!=get<3>(edges[i])) {
							ans.push_back({q, get<0>(edges[i])});
					}
					sets[b].erase(get<3>(edges[i]));
				} else {
					sets[b].insert(q);
				}
			}
			sets[a].clear();
			parent[a]=b;
			left--;
		}
		i++;
	}
	sort(ans.begin(), ans.end());
	for (auto a:ans) {
		cout<<a.second<<endl;
	}

}
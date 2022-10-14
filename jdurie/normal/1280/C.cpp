#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const ll NN = 200010;

vector<pair<ll, ll>> graph[NN];
ll sz[NN], k;

ll fillSize(ll i, ll p) {
	sz[i] = 1;
	for(auto j : graph[i])
		if(j.first != p)
			sz[i] += fillSize(j.first, i);
	return sz[i];
}

ll getBad(ll i, ll p, ll w) {
	ll bad = min(sz[i], 2 * k - sz[i]) * w;
	for(auto j : graph[i]) if(j.first != p) bad += getBad(j.first, i, j.second);
	return bad;
}

pair<ll, ll> getGood(ll i, ll p, ll w) {
	if(graph[i].empty()) return {w, 1};
	pair<ll, ll> ans = {0, 0};
	for(auto j : graph[i])
		if(j.first != p) {
			pair<ll, ll> pr = getGood(j.first, i, j.second);
			ans.first += pr.first;
			ans.second += pr.second;
		}
	if(!(ans.second % 2)) ans = {ans.first + w, 1};
	else ans.second--;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		for(ll i = 0; i < NN; i++) graph[i].clear();
		cin >> k;
		for(ll i = 0; i < 2 * k - 1; i++) {
			ll u, v, w;
			cin >> u >> v >> w;
			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
		}
		fillSize(0, -1);
		ll B = getBad(0, -1, 0);
		ll G = getGood(0, -1, 0).first;
		cout << G << " " << B << endl;
	}
	return 0;
}
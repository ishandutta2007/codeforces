#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
ll n, m;
ll deg[101000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	set<pi> x;
	for(ll f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		deg[f]-=c;
		deg[t]+=c;
	}
	for(ll i = 1; i <= n; i++)
		if(deg[i]<0)
			x.insert({deg[i], i});
	vector<pair<pi, ll>> ans;
	for(ll i = 1; i <= n; i++) {
		while(deg[i] > 0) {
			auto k = *x.begin();
			x.erase(x.begin());
			ll t = min(-k.first,  deg[i]);
			deg[i]-=t;
			ans.pb({{k.second, i}, t});
			k.first+=t;
			if(k.first < 0)
				x.insert(k);
		}
	}
	cout << ans.size() << "\n";
	for(auto i : ans)
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
}
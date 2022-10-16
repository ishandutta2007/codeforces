#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif
#define int long long
signed main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll k; cin >> k;
		vector<ll> s(n);
		vector<map<ll, ll>> dp(n);
		vector<int> p(n);
		vector<vector<int>> ch(n);

		for(int i = 1; i < n; i++){
			cin >> p[i]; p[i]--;
			ch[p[i]].push_back(i);
		}

		for(ll &x: s) cin >> x;

		function<ll(int, ll)> recurse = [&](int u, ll v){
			// v = ceil or floor k / (product of degrees above)
			if(dp[u].find(v) != dp[u].end()) return dp[u][v];
			dp[u][v] = v * s[u];
			if(ch[u].empty()) return dp[u][v];
			ll vv = v / sz(ch[u]);
			int r = v % sz(ch[u]);
			ll sm = 0;
			vector<ll> vals;
			for(int x: ch[u]){
				sm += recurse(x, vv);
				if(r != 0)
					vals.push_back(recurse(x, vv + 1) - recurse(x, vv));
			}
			sort(all(vals), greater<ll>());
			for(int i = 0; i < r; i++) sm += vals[i];
			return dp[u][v] += sm;
		};
		cout << recurse(0, k) << endl;
	}
}
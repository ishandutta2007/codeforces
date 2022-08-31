#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t = 1; 
	// cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<set<int>> adj(n);
		int ans = n;
		function<void(int, int, int)> add = [&](int x, int y, int type){
			int cur = (adj[x].empty() ? -1 : *adj[x].rbegin()) < x;
			if(type) adj[x].insert(y);
			else adj[x].erase(y);
			int nw = (adj[x].empty() ? -1 : *adj[x].rbegin()) < x;
			ans += nw - cur;
		};
		for(int i = 0; i < m; i++){
			int u, v; cin >> u >> v;
			// trace(u, v);
			u--; v--;
			add(u, v, 1);
			add(v, u, 1);
		}
		int q; cin >> q;
		while(q--){
			int type, u, v;
			cin >> type;
			if(type < 3){
				cin >> u >> v; u--; v--;
				add(u,v,type % 2);
			} else{
				cout << ans << endl;
			}
		}
	}
}
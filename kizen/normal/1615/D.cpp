#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<pair<int, int>>> way(n + 1), way2(n + 1);
		for(int i = 0; i < n - 1; ++i){
			int x, y, z; cin >> x >> y >> z;
			way[x].push_back({y, z}), way[y].push_back({x, z});
		}
		for(int i = 0; i < m; ++i){
			int x, y, z; cin >> x >> y >> z;
			way2[x].push_back({y, z}), way2[y].push_back({x, z});
		}
		vector<int> chk(n + 1), col(n + 1);
		int cant = 0;
		auto dfs = [&](auto&&self, int x, int nc)->void{
			if(chk[x] && col[x] != nc){
				cant = 1;
				return;
			}
			if(chk[x]) return;
			chk[x] = 1, col[x] = nc;
			for(auto&nxt:way[x]){
				if(nxt.second != -1){
					self(self, nxt.first, nc ^ (__builtin_popcount(nxt.second) % 2));
				}
			}
			for(auto&nxt:way2[x]){
				self(self, nxt.first, nc ^ nxt.second);
			}
		};
		for(int i = 1; i <= n; ++i){
			if(!chk[i]){
				dfs(dfs, i, 0);
			}
		}
		if(cant){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for(int i = 1; i <= n; ++i){
				for(auto&nxt:way[i]){
					if(nxt.first > i){
						if(nxt.second != -1) cout << i << ' ' << nxt.first << ' ' << nxt.second << '\n';
						else cout << i << ' ' << nxt.first << ' ' << (col[i] ^ col[nxt.first]) << '\n';
					}
				}
			}
		}
	}
	return 0;
}
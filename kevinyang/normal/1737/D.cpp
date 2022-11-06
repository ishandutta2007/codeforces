#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>adj(n+1,vector<int>(n+1,(int)1e9));
		vector<int>a(m);
		vector<int>b(m);
		vector<int>c(m);
		for(int i = 0; i<m; i++){
			int x,y,w;
			cin >> x >> y >> w;
			a[i] = x; b[i] = y; c[i] = w;
			adj[x][y] = 1;
			adj[y][x] = 1;
		}
		vector<vector<int>>dis(n+1,vector<int>(n+1));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if(i==j)dis[i][j] = 0;
				else if(adj[i][j])dis[i][j] = adj[i][j];
				else dis[i][j] = (int)1e18;
			}
		}
		
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		
		int ans = (int)1e18;
		for(int i = 0; i<m; i++){
			int x = a[i]; int y = b[i]; int w = c[i];
			for(int j = 1; j<=n; j++){
				int d1 = min(dis[x][j],dis[y][j]);
				ans = min(ans,w*(d1+dis[1][j]+dis[j][n]+2));
				ans = min(ans,w*(dis[1][x]+dis[y][n]+1));
				ans = min(ans,w*(dis[1][y]+dis[x][n]+1));
			}
		}
		cout << ans << '\n';

	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	const int mod = (int)1e9 + 7;
	while(t--){
		int n, m; cin >> n >> m;
		int s, t; cin >> s >> t;
		vector<vector<int>> way(n + 1);
		for(int i = 1; i <= m; ++i){
			int x, y; cin >> x >> y;
			way[x].push_back(y), way[y].push_back(x);
		}
		vector<int> dp(n * 2 + 1);
		vector<int> dis(n + 1, (int)1e18);
		vector<int> chk(n * 2 + 1);
		vector<vector<int>> que(n * 2 + 1, vector<int>(2));
		int f = 0, r = 0;
		que[r++] = {s, 0};
		dis[s] = 0;
		dp[s] = 1;
		while(f < r){
			int now = que[f][0], nd = que[f][1];
			int ndp = now + (nd > dis[now] ? n : 0);
			for(auto&nxt:way[now]){
				if(dis[nxt] == (int)1e18){
					dis[nxt] = nd + 1;
					if(!chk[nxt]) que[r++] = {nxt, dis[nxt]};
					chk[nxt] = 1;
					dp[nxt] = (dp[nxt] + dp[ndp]) % mod;
				}
				else if(nd + 1 == dis[nxt]){
					dp[nxt] = (dp[nxt] + dp[ndp]) % mod;
				}
				else if(nd + 1 == dis[nxt] + 1){
					dp[nxt + n] = (dp[nxt + n] + dp[ndp]) % mod;
					if(!chk[nxt + n]) que[r++] = {nxt, dis[nxt] + 1};
					chk[nxt + n] = 1;
				}
			}
			++f;
		}
		cout << (dp[t] + dp[t + n]) % mod << '\n';
	}
	return 0;
}
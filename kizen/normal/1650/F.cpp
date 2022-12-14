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
		vector<int> a(n);
		for(auto&i:a){
			cin >> i;
		}
		vector<vector<vector<int>>> gr(n + 1);
		for(int i = 0; i < m; ++i){
			int x, y, z; cin >> x >> y >> z;
			gr[x].push_back({y, z, i});
		}
		vector<int> ans;
		int ssum = 0;
		for(int i = 1; i <= n; ++i){
			int nn = (int)gr[i].size();
			vector<vector<int>> dp(nn + 1, vector<int>(100, (int)1e18));
			auto from = dp;
			dp[0][0] = 0;
			int mnt = (int)1e18;
			pair<int, int> st;
			for(int j = 0; j < nn; ++j){
				for(int x = 0; x < 100; ++x){
					int nx = x + gr[i][j][1];
					if(nx >= 100){
						if(dp[j][x] + gr[i][j][0] < mnt){
							mnt = dp[j][x] + gr[i][j][0];
							st = {j, x};
						}
					}
					else{
						if(dp[j][x] + gr[i][j][0] < dp[j + 1][nx]){
							dp[j + 1][nx] = dp[j][x] + gr[i][j][0];
							from[j + 1][nx] = x;
						}
					}
					if(dp[j][x] < dp[j + 1][x]){
						dp[j + 1][x] = dp[j][x];
						from[j + 1][x] = x;
					}
				}
			}
			if(ssum + mnt > a[i - 1]){
				ans.clear();
				ans.push_back(-1);
				break;
			}
			ssum += mnt;
			auto out = [&](auto&&self, int num, int sum)->void{
				if(num < 0){
					return;
				}
				self(self, num - 1, from[num][sum]);
				if(from[num][sum] < sum){
					ans.push_back(gr[i][num - 1][2]);
				}
			};
			out(out, st.first, st.second);
			ans.push_back(gr[i][st.first][2]);
		}
		if(ans[0] == -1){
			cout << "-1\n";
		}
		else{
			cout << (int)ans.size() << '\n';
			for(auto&i:ans) cout << i + 1 << ' ';
			cout << '\n';
		}
	}
	return 0;
}
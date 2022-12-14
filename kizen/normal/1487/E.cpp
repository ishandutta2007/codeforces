#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n[4];
	for(int i = 0; i < 4; ++i){
		cin >> n[i];
	}
	vector<vector<int>> a(4);
	for(int i = 0; i < 4; ++i){
		a[i].resize(n[i]);
		for(int j = 0; j < n[i]; ++j){
			cin >> a[i][j];
		}
	}
	int m[4];
	vector<vector<vector<int>>> no(4);
	for(int i = 1; i < 4; ++i){
		cin >> m[i];
		no[i].resize(n[i]);
		for(int j = 0; j < m[i]; ++j){
			int x, y;
			cin >> x >> y; --x, --y;
			no[i][y].push_back(x);
		}
	}
	for(int i = 1; i < 4; ++i){
		for(int j = 0; j < n[i]; ++j){
			sort(no[i][j].begin(), no[i][j].end());
		}
	}
	vector<vector<int>> dp(4);
	dp[0].resize(n[0]);
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n[0]; ++i){
		dp[0][i] = a[0][i];
		pq.push({-dp[0][i], i});
	}
	for(int i = 1; i < 4; ++i){
		dp[i].resize(n[i]);
		for(int j = 0; j < n[i]; ++j){
			vector<pair<int, int>> bk;
			dp[i][j] = -1;
			while(!pq.empty()){
				pair<int, int> top = pq.top(); pq.pop();
				bk.push_back(top);
				int pos = lower_bound(no[i][j].begin(), no[i][j].end(), top.second) - no[i][j].begin();
				if(pos < (int)no[i][j].size() && no[i][j][pos] == top.second){
					continue;
				}
				dp[i][j] = -top.first + a[i][j];
				break;
			}
			while((int)bk.size()){
				pq.push(bk.back());
				bk.pop_back();
			}
		}
		while(!pq.empty()){
			pq.pop();
		}
		for(int j = 0; j < n[i]; ++j){
			if(dp[i][j] != -1){
				pq.push({-dp[i][j], j});
			}
		}
	}
	int ans = (int)1e9;
	for(int i = 0; i < n[3]; ++i){
		if(dp[3][i] != -1){
			ans = min(ans, dp[3][i]);
		}
	}
	if(ans == (int)1e9){
		ans = -1;
	}
	cout << ans;
	return 0;
}
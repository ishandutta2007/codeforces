#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<pair<int, int>> a(N);
		vector<vector<int>> low[2];
		low[0].resize(N), low[1].resize(N);
		for(int i = 0; i < N; ++i){
			cin >> a[i].first >> a[i].second;
			low[0][i] = {a[i].first, a[i].second, i + 1};
			low[1][i] = {a[i].second, a[i].first, i + 1};
		}
		sort(low[0].begin(), low[0].end());
		sort(low[1].begin(), low[1].end());
		for(int i = 1; i < N; ++i){
			if(low[0][i - 1][1] < low[0][i][1]){
				low[0][i][1] = low[0][i - 1][1];
				low[0][i][2] = low[0][i - 1][2];
			}
		}
		for(int i = 1; i < N; ++i){
			if(low[1][i - 1][1] < low[1][i][1]){
				low[1][i][1] = low[1][i - 1][1];
				low[1][i][2] = low[1][i - 1][2];
			}
		}
		vector<int> ans(N, -1);
		for(int i = 0; i < N; ++i){
			vector<int> com = {a[i].first - 1, a[i].second, 0};
			int pos = lower_bound(low[0].begin(), low[0].end(), com) - low[0].begin(); --pos;
			if(pos >= 0 && low[0][pos][1] < a[i].second){
				ans[i] = low[0][pos][2];
			}
			pos = lower_bound(low[1].begin(), low[1].end(), com) - low[1].begin(); --pos;
			if(pos >= 0 && low[1][pos][1] < a[i].second){
				ans[i] = low[1][pos][2];
			}
		}
		for(int i = 0; i < N; ++i){
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
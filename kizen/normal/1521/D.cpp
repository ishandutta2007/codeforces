#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> way(n);
		for(int i = 0; i < n - 1; ++i){
			int x, y; cin >> x >> y; --x, --y;
			way[x].push_back(y), way[y].push_back(x);
		}
		vector<pair<int, int>> up(n);
		vector<vector<int>> line;
		auto dfs = [&](auto&&self, int x, int pr)->int{
			vector<pair<int, int>> one;
			for(auto&nxt:way[x]){
				if(nxt == pr){
					continue;
				}
				int val = self(self, nxt, x);
				if(val != -1){
					one.push_back({nxt, val});
				}
			}
			int did = 0;
			if((int)one.size() >= 2){
				up[(int)line.size()] = {x, pr};
				line.push_back({one[(int)one.size() - 2].second, one[(int)one.size() - 1].second});
				one.pop_back(), one.pop_back();
				did = 1;
			}
			while((int)one.size() >= 2){
				up[(int)line.size()] = {x, one[(int)one.size() - 1].first};
				line.push_back({one[(int)one.size() - 1].first, one[(int)one.size() - 1].second});
				one.pop_back();
			}
			if((int)one.size()){
				if(!did){
					return one[0].second;
				}
				else{
					up[(int)line.size()] = {x, one[0].first};
					line.push_back({one[0].first, one[0].second});
					return -1;
				}
			}
			else{
				if(did){
					return -1;
				}
				else{
					return x;
				}
			}
		};
		int val = dfs(dfs, 0, -1);
		if(val != -1){
			up[(int)line.size()] = {0, -1};
			line.push_back({0, val});
		}
		for(int i = 0; i < (int)line.size(); ++i){
			if(up[i].second == -1){
				swap(up[0], up[i]);
				swap(line[0], line[i]);
				break;
			}
		}
		cout << (int)line.size() - 1 << '\n';
		for(int i = 1; i < (int)line.size(); ++i){
			cout << up[i].first + 1 << ' ' << up[i].second + 1 << ' ' << line[i][0] + 1 << ' ' << line[i - 1][1] + 1 << '\n';
		}
	}
	return 0;
}
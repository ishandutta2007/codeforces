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
	int t; cin >> t;
	while(t--){
		int h, w; cin >> h >> w;
		vector<vector<int>> sol(h, vector<int>(w));
		vector<vector<bool>> fixed(h, vector<bool>(w));
		vector<pii> pos = {{0, 1}, {h - 1, 1}, {1, 0}, {1, w - 1}};
		if(w > 3){
			pos.push_back({0, w - 2});
			pos.push_back({h - 1, w - 2});
		}
		if(h > 3){
			pos.push_back({h - 2, 0});
			pos.push_back({h - 2, w - 1});
		}
		for(auto it : pos) fixed[it.first][it.second] = 1;
		int k = pos.size();
		vector<int> dx = {1, 1, 1, -1, -1, -1, 0, 0};
		vector<int> dy = {-1, 0, 1, -1, 0, 1, -1, 1};
		int ans = 0;
		for(int mask = 0; mask < (1 << k); mask++){
			vector<vector<int>> here(h, vector<int>(w));
			for(int i = 0; i < k; i++) here[pos[i].first][pos[i].second] = mask >> i & 1;
			for(int i = 0; i < h; i++){
				for(int j = 0; j < w; j++) if(!fixed[i][j]){
					if(min(i, j) >= 1 && i < h - 1 && j < w - 1) continue;
					here[i][j] = 1;
					for(int d = 0; d < 8; d++){
						int _i = i + dx[d], _j = j + dy[d];
						if(min(_i, _j) >= 0 && _i < h && _j < w){
							if(here[_i][_j]) here[i][j] = 0;
						}
					}
				}
			}
			bool ok = true;
			int cnt = 0;
			for(int i = 0; i < h; i++){
				for(int j = 0; j < w; j++) if(here[i][j]){
					cnt++;
					// if(min(i, j) >= 1 && i < h - 1 && j < w - 1) continue;
					for(int d = 0; d < 8; d++){
						int _i = i + dx[d], _j = j + dy[d];
						if(min(_i, _j) >= 0 && _i < h && _j < w){
							if(here[_i][_j]) ok = false;
						}
					}
				}
			}
			if(ok && cnt > ans){
				ans =  cnt;
				sol = here;
			}
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++) cout << sol[i][j];
			cout << endl;
		}
	}
}
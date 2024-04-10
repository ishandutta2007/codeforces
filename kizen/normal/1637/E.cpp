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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> srt;
		for(auto&i:a){
			cin >> i;
			srt.push_back(i);
		}
		sort(srt.begin(), srt.end());
		srt.erase(unique(srt.begin(), srt.end()), srt.end());
		vector<int> cnt((int)srt.size());
		for(auto&i:a){
			i = lower_bound(srt.begin(), srt.end(), i) - srt.begin();
			++cnt[i];
		}
		vector<int> csrt;
		for(int i = 0; i < (int)srt.size(); ++i){
			csrt.push_back(cnt[i]);
		}
		sort(csrt.begin(), csrt.end());
		csrt.erase(unique(csrt.begin(), csrt.end()), csrt.end());
		vector<vector<int>> ys((int)csrt.size());
		for(int i = 0; i < (int)srt.size(); ++i){
			cnt[i] = lower_bound(csrt.begin(), csrt.end(), cnt[i]) - csrt.begin();
			ys[cnt[i]].push_back(srt[i]);
		}
		vector<vector<int>> no((int)srt.size());
		for(int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			x = lower_bound(srt.begin(), srt.end(), x) - srt.begin();
			y = lower_bound(srt.begin(), srt.end(), y) - srt.begin();
			no[y].push_back(x), no[x].push_back(y);
		}
		int ans = 0;
		for(int i = 0; i < (int)srt.size(); ++i){
			sort(no[i].begin(), no[i].end());
		}
		for(int i = 0; i < (int)csrt.size(); ++i){
			sort(ys[i].begin(), ys[i].end());
			reverse(ys[i].begin(), ys[i].end());
		}
		auto cang = [&](int vx, int vy)->bool{
			vx = lower_bound(srt.begin(), srt.end(), vx) - srt.begin();
			vy = lower_bound(srt.begin(), srt.end(), vy) - srt.begin();
			int pos = lower_bound(no[vx].begin(), no[vx].end(), vy) - no[vx].begin();
			if(pos < (int)no[vx].size() && no[vx][pos] == vy) return 0;
			return 1;
		};
		for(int i = 0; i < (int)csrt.size(); ++i){
			for(int j = i + 1; j < (int)csrt.size(); ++j){
				int k = 0;
				while(k < (int)ys[j].size()){
					if(cang(ys[i][0], ys[j][k])) break;
					else ++k;
				}
				if(k < (int)ys[j].size()){
					ma(ans, (csrt[i] + csrt[j]) * (ys[i][0] + ys[j][k]));
				}
				for(int x = 0; x < k; ++x){
					int y = 0;
					while(y < (int)ys[i].size()){
						if(cang(ys[j][x], ys[i][y])) break;
						else ++y;
					}
					if(y < (int)ys[i].size()){
						ma(ans, (csrt[i] + csrt[j]) * (ys[i][y] + ys[j][x]));
					}
				}
			}
		}
		for(int i = 0; i < (int)csrt.size(); ++i){
			for(int j = 0; j < (int)ys[i].size(); ++j){
				int k = 0;
				while(k < (int)ys[i].size()){
					if(k == j){
						++k; continue;
					}
					if(cang(ys[i][j], ys[i][k])) break;
					++k;
				}
				if(k < (int)ys[i].size()){
					ma(ans, (csrt[i] * 2) * (ys[i][j] + ys[i][k]));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
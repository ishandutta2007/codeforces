#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> pos[2];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> a(n);
		vector<int> b(n), dis(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		pos[0].clear(), pos[1].clear();
		for(int i = 0; i < n; ++i){
			char c;
			cin >> c;
			b[i] = (c == 'R' ? 0 : 1);
			if(!b[i]){
				dis[i] = a[i];
			}
			else{
				dis[i] = 2 * m - a[i];
			}
			pos[dis[i] % 2].push_back({a[i], b[i], i});
		}
		vector<int> ans(n, -1);
		for(int k = 0; k < 2; ++k){
			sort(pos[k].begin(), pos[k].end());
			vector<vector<int>> stk;
			for(auto&i:pos[k]){
				if(i[1] && (int)stk.size() && !stk.back()[1]){
					int val = (i[0] - stk.back()[0]) / 2;
					ans[i[2]] = ans[stk.back()[2]] = val;
					stk.pop_back();
				}
				else{
					stk.push_back(i);
				}
			}
			int l = 0;
			while(l + 1 < (int)stk.size() && stk[l][1] && stk[l + 1][1]){
				int val = stk[l][0] + (stk[l + 1][0] - stk[l][0]) / 2;
				ans[stk[l][2]] = ans[stk[l + 1][2]] = val;
				l += 2;
			}
			int r = (int)stk.size() - 1;
			while(r > 0 && !stk[r][1] && !stk[r - 1][1]){
				int val = m - stk[r][0] + (stk[r][0] - stk[r - 1][0]) / 2;
				ans[stk[r][2]] = ans[stk[r - 1][2]] = val;
				r -= 2;
			}
			if(l < (int)stk.size() && r >= 0 && stk[l][1] && !stk[r][1]){
				int val = (m + stk[l][0] + m - stk[r][0]) / 2;
				ans[stk[l][2]] = ans[stk[r][2]] = val;
			}
		}
		for(int i = 0; i < n; ++i){
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int ans = 10;
		int cnt[2] = {0, 0};
		for(int i = 0; i < 10; ++i){
			if(s[i] == '1') ++cnt[i % 2];
			else if(s[i] == '?' && i % 2 == 0) ++cnt[i % 2];
			int val[2] = {0, 0};
			for(int j = i + 1; j < 10; ++j){
				++val[j % 2];
			}
			if(cnt[0] + val[0] < cnt[1] || cnt[1] + val[1] < cnt[0]){
				ans = i + 1; break;
			}
		}
		cnt[0] = cnt[1] = 0;
		for(int i = 0; i < 10; ++i){
			if(s[i] == '1') ++cnt[i % 2];
			else if(s[i] == '?' && i % 2 == 1) ++cnt[i % 2];
			int val[2] = {0, 0};
			for(int j = i + 1; j < 10; ++j){
				++val[j % 2];
			}
			if(cnt[0] + val[0] < cnt[1] || cnt[1] + val[1] < cnt[0]){
				umi(ans, i + 1); break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
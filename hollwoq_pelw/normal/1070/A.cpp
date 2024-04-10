#include <bits/stdc++.h>
using namespace std;

int d, s, dp[505][5005];
pair<pair<int, int>, int> tr[505][5005];

signed main(){
    cin >> d >> s;
    queue<pair<int, int>> q;
    memset(dp, -1, sizeof dp);
    q.push({0, 0});
    dp[0][0] = 0;
    while(q.size()){
        int md = q.front().first, sum = q.front().second; q.pop();
        
        if (md == 0 && sum == s){
			int l = dp[0][s];
			string ans = "";
			while(l--) {
				ans = (char)(tr[md][sum].second + '0') + ans;
				pair<int, int> st = tr[md][sum].first;
				md = st.first, sum = st.second;
			}
			cout << ans << endl;
			return 0;
        }
        
        for (int i = 0; i < 10; i++){
            if (sum + i <= s){
                int nmd = (md * 10 + i) % d;
				int nxt = sum + i;
				if (dp[nmd][nxt] == -1) {
					dp[nmd][nxt] = dp[md][sum] + 1;
					tr[nmd][nxt] = {{md, sum}, i};
					q.push({nmd, nxt});
				}
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
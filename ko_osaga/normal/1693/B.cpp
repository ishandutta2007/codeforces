#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tc; cin >> tc;
	for(int i = 0; i < tc; i++){
		int n; cin >> n;
		vector<vector<int>> gph(n);
		int p;
		for(int i = 1; i < n; i++){
			cin >> p;
			gph[p - 1].push_back(i);
		}
		vector<pi> a(n);
		vector<pi> dp(n);
		for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
		int cnt = 0;
		for(int i = n - 1; i >= 0; i--){
			for(auto &j : gph[i]){
				dp[i].first += dp[j].first;
				dp[i].second += dp[j].second;
			}
			if(dp[i].second < a[i].first){
				cnt++;
				dp[i] = a[i];
				continue;
			}
			dp[i].first = 0;
			dp[i].first = max(dp[i].first, a[i].first);
			dp[i].second = min(dp[i].second, a[i].second);
		}
		cout << cnt << "\n";
	}
}
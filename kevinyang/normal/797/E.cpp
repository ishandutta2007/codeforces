#include <bits/stdc++.h>
using namespace std;
#define int long long
const int sq = 350;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int q;
	cin >> q;
	vector<pair<int,int>>queries(q); int base = (int)1e9;
	vector<int>ans(q);
	int cur = 0;
	for(int i = 0; i<q; i++){
		int p,k;
		cin >> p >> k;
		queries[i] = {k*base+p,i};
	}
	vector<int>dp(n+1);
	sort(queries.begin(),queries.end());
	for(int i = 0; i<q; i++){
		int k = queries[i].first/base; int p = queries[i].first%base; int ind = queries[i].second;
		if(k<sq){
			while(cur<k){
				cur++;
				for(int i = n; i>=1; i--){
					if(i+cur+arr[i]>n){
						dp[i] = 1;
					}
					else{
						dp[i] = dp[i+cur+arr[i]] + 1;
					}
				}
			}
			ans[ind] = dp[p];
		}
		else{
			int cnt = 0;
			int idx = p;
			while(idx<=n){
				cnt++; idx+=k+arr[idx];
			}
			ans[ind] = cnt;
		}
	}
	for(int i = 0; i<q; i++){
		cout << ans[i] << "\n";
	}
	return 0;
}
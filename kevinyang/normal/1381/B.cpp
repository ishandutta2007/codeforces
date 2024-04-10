#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(2*n);
		for(int i = 0; i<2*n; i++){
			cin >> arr[i];
		}
		vector<int>items;
		int cur = 1;
		int start = arr[0];
		for(int i = 1; i<2*n; i++){
			if(arr[i]>start){
				items.push_back(cur);
				cur = 1;
				start = arr[i];
			}
			else{
				cur++;
			}
		}
		items.push_back(cur);
		vector<bool>dp(2*n+1);
		dp[0] = true;
		for(int nxt:items){
			for(int i = 2*n; i>=0; i--){
				if(dp[i]){
					dp[i+nxt] = true;
				}
			}
		}
		cout << "\n";
		if(dp[n])cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
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
		vector<int>arr(n);
		vector<int>freq(n+1);
		vector<bool>vis(n+1);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		freq[arr[0]]+=2;
		vis[arr[0]] = true;
		for(int i = 0; i<n-1; i++){
			if(arr[i]!=arr[i+1]){
				freq[arr[i+1]]++;
				if(!vis[arr[i+1]]){
					vis[arr[i+1]] = true;
					freq[arr[i+1]]++;
				}
			}
		}
		freq[arr[0]]--;
		freq[arr[n-1]]--;
		int ans = 1e18;
		for(int i = 1; i<=n; i++){
			if(vis[i]){
				ans = min(ans,freq[i]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
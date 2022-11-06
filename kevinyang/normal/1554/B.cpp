#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		if(n<=1000){
			int ans = -(int)1e18;
			for(int i = 1; i<=n; i++){
				for(int j = i+1; j<=n; j++){
					ans = max(ans,i*j-k*(arr[i]|arr[j]));
				}
			}
			cout << ans << "\n";
		}
		else{
			int ans = -(int)1e18;
			for(int i = n-1000; i<=n; i++){
				for(int j = i+1; j<=n; j++){
					ans = max(ans,i*j-k*(arr[i]|arr[j]));
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
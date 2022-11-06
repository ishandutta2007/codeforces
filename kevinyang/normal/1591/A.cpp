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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		int ans = arr[1]+1;
		for(int i = 2; i<=n; i++){
			if(arr[i]==0&&arr[i-1]==0){
				ans = -(int)1e9;
			}
			if(arr[i]==1&&arr[i-1]==0){
				ans++;
			}
			if(arr[i]==1&&arr[i-1]==1){
				ans+=5;
			}
		}
		ans = max(ans,-1LL);
		cout << ans << "\n";
	}
	return 0;
}
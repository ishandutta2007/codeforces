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
		int cur = 0;
		int ans = 0;
		for(int i = n-1; i>=1; i--){
			if(arr[i]<arr[i+1]*2)cur++;
			else cur = 0;
			if(cur>=k)ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
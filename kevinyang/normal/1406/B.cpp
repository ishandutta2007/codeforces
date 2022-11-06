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
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		int ans = 1;
		for(int i = n-1; i>=n-5; i--){
			ans*=arr[i];
		}
		int cur = arr[0]*arr[1];
		for(int i = n-1; i>=n-3; i--){
			cur*=arr[i];
		}
		ans = max(ans,cur);
		cur = arr[0]*arr[1]*arr[2]*arr[3]*arr[n-1];
		ans = max(ans,cur);
		cout << ans << "\n";
	}
	return 0;
}
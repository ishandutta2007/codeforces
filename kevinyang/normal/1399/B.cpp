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
		vector<int>arr2(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<n; i++){
			cin >> arr2[i];
		}
		int mn1 = (int)1e18; int mn2 = (int)1e18;
		for(int i = 0; i<n; i++){
			mn1 = min(mn1,arr[i]);
			mn2 = min(mn2,arr2[i]);
		}
		int ans = 0;
		for(int i = 0; i<n; i++){
			ans+=max(arr[i]-mn1,arr2[i]-mn2);
		}
		cout << ans << "\n";
	}
	return 0;
}
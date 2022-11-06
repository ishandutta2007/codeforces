#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,l,r;
		cin >> n >> l >> r;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int ans = 0;
		sort(arr.begin(),arr.end());
		for(int i = 0; i<n; i++){
			int v = lower_bound(arr.begin()+i+1,arr.end(),l-arr[i])-arr.begin();
			int v2 = --upper_bound(arr.begin()+i+1,arr.end(),r-arr[i])-arr.begin();
			ans+=max(0LL,v2-v+1);
		}
		cout << ans << "\n";
	}
	return 0;
}
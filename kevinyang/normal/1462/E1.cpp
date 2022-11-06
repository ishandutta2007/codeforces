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
		sort(arr.begin(),arr.end()); arr.push_back((int)1e9);
		int ans = 0;
		for(int i = 0; i<n-2; i++){
			int val = upper_bound(arr.begin(),arr.end(),arr[i]+2)-arr.begin()-1;
			val-=i;
			ans+=val*(val-1)/2;
		}
		cout << ans << "\n";
	}
	return 0;
}
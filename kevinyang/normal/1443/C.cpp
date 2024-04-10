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
		vector<pair<int,int>>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i].first;
		}
		for(int i = 0; i<n; i++){
			cin >> arr[i].second;
		}
		sort(arr.begin(),arr.end());
		int low = 0;
		int high = 1e9+5;
		int mid = (low+high)/2;
		int ans = 1e9;
		while(low+1<high){
			int sum = 0;
			int val = 0;
			for(int i = 0; i<n; i++){
				if(arr[i].first>mid){
					sum+=arr[i].second;
				}
				else{
					val = max(val,arr[i].first);
				}
			}
			ans = min(ans,max(sum,val));
			if(val<=sum){
				low = mid;
			}
			else{
				high = mid;
			}
			mid = (low+high)/2;
		}
		cout << ans << "\n";
	}
	return 0;
}
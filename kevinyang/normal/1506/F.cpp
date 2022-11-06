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
		vector<pair<int,int>>arr(n+1); arr[n] = {1,1};
		for(int i = 0; i<n; i++){
			cin >> arr[i].first;
		}
		for(int i = 0; i<n; i++){
			cin >> arr[i].second;
		}
		sort(arr.begin(),arr.end());
		int ans = 0;
		for(int i = 0; i<n; i++){
			int dis = arr[i+1].first-arr[i].first;
			int left = arr[i].second+dis-arr[i+1].second;
			if(left){
				if((arr[i].first+arr[i].second)%2==1){
					ans+=(left+1)/2;
				}
				else{
					ans+=left/2;
				}
			}
			else{
				if((arr[i].first+arr[i].second)%2==0){
					ans+=dis;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
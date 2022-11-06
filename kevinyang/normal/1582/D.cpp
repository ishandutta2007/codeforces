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
			arr[i].second = i;
		}
		sort(arr.begin(),arr.end());
		if(arr[0].first+arr[1].first==0){
			reverse(arr.begin(),arr.end());
		}
		vector<int>ans(n);
		if(n%2==1){
			int v = arr[0].first+arr[1].first; int v2 = arr[2].first;
			int u = __gcd(abs(v),abs(v2));
			v/=u; v2/=u;
			ans[arr[0].second] = v2; ans[arr[1].second] = v2; ans[arr[2].second] = -v;
			for(int i = 3; i<n; i+=2){
				int u = __gcd(abs(arr[i].first),abs(arr[i+1].first));
				ans[arr[i].second] = -arr[i+1].first/u;
				ans[arr[i+1].second] = arr[i].first/u;
			}
		}
		else{
			for(int i = 0; i<n; i+=2){
				int u = __gcd(abs(arr[i].first),abs(arr[i+1].first));
				ans[arr[i].second] = -arr[i+1].first/u;
				ans[arr[i+1].second] = arr[i].first/u;
			}
		}
		for(int i = 0; i<n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
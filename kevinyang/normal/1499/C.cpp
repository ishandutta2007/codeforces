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
		int ans = (int)1e18;
		int mnodd = arr[1];
		int mneven = arr[2];
		int sumodd = arr[1];
		int sumeven = 0;
		for(int i = 2; i<=n; i++){
			if(i%2==0){
				mneven = min(mneven,arr[i]);
				sumeven +=arr[i];
			}
			else{
				mnodd = min(mnodd,arr[i]);
				sumodd+=arr[i];
			}
			ans = min(ans,sumodd+(n-(i+1)/2)*mnodd+sumeven+(n-i/2)*mneven);
		}
		cout << ans << "\n";
	}
	return 0;
}
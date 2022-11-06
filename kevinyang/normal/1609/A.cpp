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
		int cnt = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			while(arr[i]%2==0){
				arr[i]/=2;
				cnt++;
			}
		}
		sort(arr.begin(),arr.end());
		for(int i = 0; i<cnt; i++){
			arr[n-1]*=2;
		}
		int ans = 0;
		for(int i = 0; i<n; i++){
			ans+=arr[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
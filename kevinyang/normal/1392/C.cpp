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
		int ans = 0;
		for(int i = n-1; i>0; i--){
			if(arr[i]<arr[i-1])ans+=arr[i-1]-arr[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
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
		vector<int>arr2(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> arr2[i];
		}
		int ans = 0;
		for(int i = 2; i<=n; i++){
			ans+=min(abs(arr[i]-arr[i-1])+abs(arr2[i]-arr2[i-1]),abs(arr[i]-arr2[i-1])+abs(arr2[i]-arr[i-1]));
		}
		cout << ans << "\n";
	}
	return 0;
}
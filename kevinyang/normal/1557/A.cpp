#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
		sort(arr.begin(),arr.end());
		double ans = -(int)1e18;
		for(int i = 1; i<n; i++){
			arr[i]+=arr[i-1];
		}
		cout << fixed << setprecision(10);
		for(int i = 0; i<n-1; i++){
			ans = max(ans,(double)arr[i]/(i+1)+((double)arr[n-1]-arr[i])/(n-i-1));
		}
		cout << ans << "\n";
	}
	return 0;
}
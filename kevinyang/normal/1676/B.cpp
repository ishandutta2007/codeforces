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
		int sum = 0;
		int mn = (int)1e9;
		for(int i = 1; i<=n; i++){
			sum+=arr[i];
			mn = min(mn,arr[i]);
		}
		cout << sum-mn*n << "\n";
	}
	return 0;
}
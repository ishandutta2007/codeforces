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
		sort(arr.begin(),arr.end());
		int mx = arr[n];
		int sum = 0;
		for(int i = 1; i<n; i++){
			sum+=arr[i];
		}
		if(sum<mx*(n-2)){
			cout << mx*(n-2)-sum << "\n";
		}
		else{
			if((sum+mx)%(n-1)==0){
				cout << "0\n";
			}
			else{
				cout << n-1 - (sum+mx)%(n-1) << "\n";
			}
		}
	}
	return 0;
}
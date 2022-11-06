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
		sort(arr.begin(),arr.end());
		if(arr[0]+arr[1]<=arr[n-1]){
			cout << "1 2 " << n << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}
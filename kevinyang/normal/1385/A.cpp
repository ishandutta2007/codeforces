#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<int>arr(3);
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr.begin(),arr.end());
		if(arr[1]==arr[2]){
			cout << "YES\n";
			cout << arr[0] << " " << arr[0] << " " << arr[1] << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
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
		vector<int>arr(2*n);
		for(int i = 0; i<2*n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		for(int i = 0; i<n; i++){
			cout << arr[i] << " ";
			cout << arr[i+n] << " ";
		}
		cout << "\n";
	}
	return 0;
}
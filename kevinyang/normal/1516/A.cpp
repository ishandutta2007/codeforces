#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<n-1; i++){
			while(arr[i]&&k){
				arr[i]--; arr[n-1]++; k--;
			}
		}
		for(int i = 0; i<n; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
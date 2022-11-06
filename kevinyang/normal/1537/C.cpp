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
		int mn = (int)1e18;
		for(int i = 0; i<n-1; i++){
			mn = min(arr[i+1]-arr[i],mn);
		}
		for(int i = 0; i<n-1; i++){
			if(arr[i+1]-arr[i]==mn){
				cout << arr[i] << " ";
				for(int j = i+2; j<n; j++){
					cout << arr[j] << " ";
				}
				for(int j = 0; j<i; j++){
					cout << arr[j] << " ";
				}
				cout << arr[i+1] << "\n";
				break;
			}
		}
	}
	return 0;
}
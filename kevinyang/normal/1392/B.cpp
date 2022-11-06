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
		int mx = -1*(int)1e18;
		for(int i = 0; i<n; i++){
			mx = max(arr[i],mx);
		}
		k--;
		for(int i = 0; i<n; i++){
			arr[i] = mx-arr[i];
		}
		if(k==0){
			for(int i = 0; i<n; i++){
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
		else{
			vector<int>arr2(n);
			int mx2 = -1*(int)1e18;
			for(int i = 0; i<n; i++){
				mx2 = max(mx2,arr[i]);
			}
			for(int i = 0; i<n; i++){
				arr2[i] = mx2-arr[i];
			}
			if(k%2==0){
				for(int i = 0; i<n; i++){
					cout << arr[i] << " ";
				}
			}
			else{
				for(int i = 0; i<n; i++){
					cout << arr2[i] << " ";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
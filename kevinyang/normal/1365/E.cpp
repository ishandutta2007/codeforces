#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	if(n<=3){
		int ans = 0;
		for(int i = 0; i<n; i++){
			ans|=arr[i];
		}
		cout << ans << "\n";
		return 0;
	}
	int mx = 0;
	for(int i = 0; i<n-2; i++){
		for(int j = i+1; j<n-1; j++){
			for(int k = j+1; k<n; k++){
				mx = max(arr[i]|arr[j]|arr[k],mx);
			}
		}
	}
	cout << mx << "\n";
	return 0;
}
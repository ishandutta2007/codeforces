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
		if(n==1){
			int x;
			cin >> x;
			cout << x << "\n";
			continue;
		}
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		int sum = arr[0] + arr[n-1];
		for(int i = 1; i<n; i++){
			sum+=abs(arr[i]-arr[i-1]);
		}
		for(int i = 1; i<n-1; i++){
			if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
				sum-=arr[i]-max(arr[i-1],arr[i+1]);
			}
		}
		if(arr[0]>arr[1])sum-=arr[0]-arr[1];
		if(arr[n-1]>arr[n-2])sum-=arr[n-1]-arr[n-2];
		cout << sum << "\n";
	}
	return 0;
}
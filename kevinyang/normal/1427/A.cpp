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
		int sum = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			sum+=arr[i];
		}
		sort(arr.begin(),arr.end());
		if(sum==0){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if(sum>0){
			for(int i = n-1; i>=0; i--){
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
		else{
			for(int i = 0; i<n; i++){
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		int sum = 0;
		for(int i = 0; i<n; i++){
			sum+=arr[i];
		}
		if(sum==x){
			cout << "NO\n";
			continue;
		}
		sum = 0;
		for(int i = 0; i<n; i++){
			sum+=arr[i];
			if(sum==x){
				swap(arr[i],arr[i+1]);
			}
		}
		cout << "YES\n";
		for(int i = 0; i<n; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
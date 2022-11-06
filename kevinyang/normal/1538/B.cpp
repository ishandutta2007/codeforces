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
		if(sum%n!=0){
			cout << "-1\n";
			continue;
		}
		int sum2 = 0;
		for(int i = 0; i<n; i++){
			if(arr[i]>sum/n){
				sum2++;
			}
		}
		cout << sum2 << "\n";
	}
	return 0;
}
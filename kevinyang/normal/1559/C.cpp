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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			arr[i]^=1;
		}
		int sum = 0;
		for(int i = 1; i<=n; i++){
			sum+=arr[i];
		}
		if(sum==n){
			for(int i = 1; i<=n+1; i++){
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}
		int idx = 0;
		for(int i = 1; i<=n; i++){
			if(arr[i]==0){
				idx = i;
				break;
			}
		}
		for(int i = 1; i<idx; i++){
			cout << i << " ";
		}
		cout << n+1 << " ";
		for(int i = idx; i<=n; i++){
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}
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
		vector<bool>vis(n+1);
		for(int i = 0; i<2*n; i++){
			if(vis[arr[i]]){
				continue;
			}
			cout << arr[i] << " ";
			vis[arr[i]] = true;
		}
		cout << "\n";
	}
	return 0;
}
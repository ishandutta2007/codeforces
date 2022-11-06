#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>arr(n);
		vector<int>arr2(m);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<m; i++){
			cin >> arr2[i];
		}
		int ans = 0;
		bool f = false;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				if(f){
					continue;
				}
				if(arr[i]==arr2[j]){
					f = true;
					ans = arr[i];
				}
			}
		}
		if(f){
			cout << "YES\n";
			cout << "1 " << ans << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
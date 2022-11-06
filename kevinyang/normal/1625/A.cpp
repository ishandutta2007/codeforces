#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,l;
		cin >> n >> l;
		vector<int>arr(n);
		int ans = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<l; i++){
			int cnt = 0;
			for(int j = 0; j<n; j++){
				if(arr[j]&(1<<i)){
					cnt++;
				}
			}
			if(cnt*2>=n){
				ans+=(1<<i);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
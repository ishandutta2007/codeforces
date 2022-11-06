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
		vector<int>arr(1000);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			arr[x]++;
		}
		int ans = 0;
		for(int i = 0; i<=100; i++){
			if(arr[i]<2){
				ans = i;
				break;
			}
		}
		for(int i = 0; i<=100; i++){
			if(arr[i]<1){
				ans+=i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
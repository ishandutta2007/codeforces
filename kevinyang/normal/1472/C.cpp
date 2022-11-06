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
		}
		vector<int>ans(n+1);
		int mx = 0;
		for(int i = n; i>0; i--){
			if(i+arr[i]>n){
				ans[i] = arr[i];
			}
			else{
				ans[i] = arr[i]+ans[i+arr[i]];
			}
			mx = max(mx,ans[i]);
		}
		cout << mx << "\n";
	}
	return 0;
}
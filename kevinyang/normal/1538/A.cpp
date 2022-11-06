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
		int mn = 1000; int mx = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			mn = min(mn,arr[i]);
			mx = max(mx,arr[i]);
		}
		int x = 0; int y = 0;
		for(int i = 0; i<n; i++){
			if(arr[i]==mn)x = i;
			if(arr[i]==mx)y = i;
		}
		cout << min({max(x,y)+1,n-min(x,y),x+1+n-y,y+1+n-x}) << "\n";
	}
	return 0;
}
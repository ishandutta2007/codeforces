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
		vector<int>arr(2*n+1);
		for(int i = 1; i<=2*n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		bool f  = true;
		for(int i = 1; i<=n; i++){
			if(arr[i+n]-x>=arr[i])continue;
			f = false;
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
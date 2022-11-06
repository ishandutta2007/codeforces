#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		bool f = false;
		if(arr[n-1]<=d)f = true;
		if(arr[0]+arr[1]<=d)f = true;
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
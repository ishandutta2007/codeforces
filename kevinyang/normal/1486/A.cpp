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
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		bool f = true;
		for(int i = 0; i<n; i++){
			if(arr[i]<i)f = false;
			arr[i+1]+=arr[i]-i;
			arr[i] = i;
		}
		if(f)cout << "YES\n";
		else cout << "No\n";
	}	
	return 0;
}
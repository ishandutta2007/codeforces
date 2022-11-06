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
		vector<int>arr2(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			arr2[i] = arr[i];
		}
		sort(arr2.begin(),arr2.end());
		bool f = true;
		for(int i = 0; i<n; i++){
			if(arr[i]!=arr2[i])f = false;
		}
		if(f)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	//cerr << __gcd(0,0) << "\n";
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		vector<int>arr2(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			arr2[i] = arr[i];
		}
		sort(arr.begin()+1,arr.end());
		if(arr[1]==arr[n]){
			cout << "-1\n";
			continue;
		}
		int v = 0;
		for(int i = 1; i<n; i++){
			int dif = arr2[i+1]-arr2[i];
			dif = abs(dif);
			v = __gcd(dif,v);
		}
		cout << v << "\n";
	}
	return 0;
}
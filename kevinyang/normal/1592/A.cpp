#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,h;
		cin >> n >> h;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		int v = h/(arr[n-1]+arr[n-2])*2;
		int rem = h%(arr[n-1]+arr[n-2]);
		if(rem==0){

		}
		else if(rem<=arr[n-1]){
			v++;
		}
		else{
			v+=2;
		}
		cout << v << "\n";
	}
	return 0;
}
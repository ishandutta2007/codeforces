#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		bool f = true;
		int prevmx = arr[0]; int prevmn = arr[0];
		for(int i = 1; i<n-1; i++){
			int mx = min(arr[i]+k-1,prevmx+k-1);
			int mn = max(prevmn-k+1,arr[i]);
			if(prevmx+k<=mn||prevmn-k>=mx){
				f = false;
			}
			prevmx = mx; prevmn = mn;
		}
		int mx = arr[n-1]; int mn = arr[n-1];
		if(prevmx+k<=mn||prevmn-k>=mx){
			f = false;
		}
		if(f){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}
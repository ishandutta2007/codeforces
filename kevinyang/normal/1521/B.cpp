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
		int mn = (int)1e18; int idx = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<n; i++){
			if(arr[i]<mn){
				mn = arr[i];
				idx = i;
			}
		}
		bool f = (idx==0);
		cout << n-f << "\n";
		if(!f)cout << "1 " << idx+1 << " " << arr[idx] << " " << idx+arr[idx] << "\n";
		for(int i = 1; i<n; i++){
			cout << 1 << " " << i+1 << " " << mn << " " << i+mn << "\n";
		}
	}
	return 0;
}
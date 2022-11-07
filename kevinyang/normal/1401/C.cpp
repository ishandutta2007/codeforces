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
		vector<int>sorted(n);
		int mn = (int)1e18;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			sorted[i] = arr[i]; mn = min(mn,arr[i]);
		}
		sort(sorted.begin(), sorted.end());
		bool f = true;
		for(int i = 0; i<n; i++){
			if(sorted[i]!=arr[i]){
				if(arr[i]%mn!=0){
					f = false;
				}
			}

		}
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
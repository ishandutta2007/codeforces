#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int mxval = (1<<15)-1;
	map<vector<int>,int>ans;
	map<vector<int>,bool>hm;
	for(int m = 0; m<(1<<15); m++){
		vector<int>arr2(n+1);
		int mn = (int)1e18;
		for(int i = 1; i<=n; i++){
			arr2[i] = __builtin_popcount(m^(arr[i]&mxval));
			mn = min(mn,arr2[i]);
		}
		for(int i = 1; i<=n; i++){
			arr2[i]-=mn;
		}
		hm[arr2] = true;
		ans[arr2] = m;
	}
	for(int m = 0; m<(1<<15); m++){
		vector<int>arr2(n+1);
		int mx = 0;
		for(int i = 1; i<=n; i++){
			arr2[i] = __builtin_popcount(m^(arr[i]>>15));
			mx = max(mx,arr2[i]);
		}
		for(int i = 1; i<=n; i++){
			arr2[i] = mx-arr2[i];
		}
		if(hm[arr2]){
			cout << ((m<<15)+ans[arr2]) << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
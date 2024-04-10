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
		vector<int>arr2(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			arr2[i] = arr[i];
		}
		sort(arr2.begin(),arr2.end());
		map<int,int>ind;
		for(int i = 0; i<n; i++){
			ind[arr2[i]] = i;
		}
		int cnt = 0;
		int prev = -(int)2e9;
		cnt = 1;
		for(int i = 0; i<n; i++){
			if(prev!=-(int)2e9&&ind[prev]+1!=ind[arr[i]]){
				cnt++;
			}
			prev = arr[i];
		}
		//cout << cnt << " ";
		if(cnt<=k)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
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
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>arr2(n+1);
		for(int i = 1; i<=n; i++){
			arr2[i] = arr[i];
		}
		sort(arr2.begin()+1,arr2.end());
		vector<vector<int>>ans;
		for(int k = n; k>=1; k--){
			int i = 1;
			while(i<=n){
				if(arr[i]==arr2[k])break;
				i++;
			}
			if(arr[i]==arr2[i])continue;
			int idx = 0;
			for(int j = n; j>=1; j--){
				if(arr2[j]==arr[i]){
					idx = j;
					break;
				}
			}
			int old = arr[i];
			arr.erase(arr.begin()+i);
			arr.insert(arr.begin()+idx,old);
			ans.push_back({i,idx,1});
		}
		cout << ans.size() << "\n";
		for(auto nxt: ans){
			cout << nxt[0] << " " << nxt[1] << " " << nxt[2] << "\n";
		}
	}
	return 0;
}
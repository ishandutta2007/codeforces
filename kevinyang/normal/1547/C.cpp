#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int k,n,m;
		cin >> k >> n >> m;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		vector<int>arr2(m);
		for(int i = 0; i<m; i++){
			cin >> arr2[i];
		}
		int cur = 0;
		int cur2 = 0;
		vector<int>ans;
		for(int tt = 0; tt<n+m; tt++){
			while(cur<n&&arr[cur]<=k){
				ans.push_back(arr[cur]);
				if(arr[cur]==0)k++;
				cur++;
				//k++;
			}
			while(cur2<m&&arr2[cur2]<=k){
				ans.push_back(arr2[cur2]);
				if(arr2[cur2]==0)k++;
				cur2++;
				//k++;
			}
		}
		if(ans.size()!=n+m){
			cout << "-1\n";
		}
		else{
			for(int nxt: ans){
				cout << nxt << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
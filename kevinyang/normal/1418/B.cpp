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
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		vector<int>lock(n);
		for(int i = 0; i<n; i++){
			cin >> lock[i];
		}
		vector<int>ans;
		for(int i = 0; i<n; i++){
			if(lock[i]==0)ans.push_back(arr[i]);
		}
		sort(ans.begin(),ans.end());
		int ind = ans.size()-1;
		for(int i = 0; i<n; i++){
			if(lock[i]==1)cout << arr[i] << " ";
			else{
				cout << ans[ind] << " "; ind--;
			}
		}
		cout << "\n";
	}
	return 0;
}
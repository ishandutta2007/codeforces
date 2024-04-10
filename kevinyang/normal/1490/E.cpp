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
		vector<int>arr2;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			arr2.push_back(arr[i]);
		}
		sort(arr2.begin(),arr2.end());
		int ans = 0; int cur = 0;
		for(int i = 0; i<n; i++){
			if(cur<arr2[i])ans = arr2[i];
			cur+=arr2[i];
		}
		vector<int>val;
		for(int i = 1; i<=n; i++){
			if(arr[i]>=ans)val.push_back(i);
		}
		cout << val.size() << "\n";
		for(int nxt: val){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}
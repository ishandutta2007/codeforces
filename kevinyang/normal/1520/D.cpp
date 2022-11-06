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
		map<int,int>hm;
		int ans = 0;
		for(int i = 1; i<=n; i++){
			ans+=hm[arr[i]-i];
			hm[arr[i]-i]++;
		}
		cout << ans << "\n";
	}
	return 0;
}
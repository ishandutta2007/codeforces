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
		int sum = 0;
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			sum+=arr[i];
		}
		int ans = 0;
		map<int,int>hm;
		for(int i = 1; i<=n; i++){
			ans+=hm[n*arr[i]];
			hm[2*sum-n*arr[i]]++;
		}
		cout << ans << "\n";
	}
	return 0;
}
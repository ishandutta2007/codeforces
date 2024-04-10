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
		
		vector<int>arr(n+5);
		vector<int>arr2(n+5);
		vector<int>psa(n+5);
		vector<int>suf(n+5);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> arr2[i];
		}
		if(n==1){
			cout << "0\n";
			continue;
		}
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr2[i];
		}
		for(int i = n; i>=1; i--){
			suf[i] = suf[i+1]+arr[i];
		}
		int ans = (int)1e18;
		ans = min(suf[2],psa[n-1]);
		for(int i = 2; i<n; i++){
			ans = min(ans,max(suf[i+1],psa[i-1]));
		}
		cout << ans << "\n";
	}
	return 0;
}
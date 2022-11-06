#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,s;
		cin >> n >> s;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		int ans = (int)1e9;
		for(int i = 1; i<=n; i++){
			int k = s+psa[i-1];
			int idx = upper_bound(psa.begin(),psa.end(),k)-psa.begin()-1;
			if(psa[idx]==k){
				ans = min(n-(idx-i+1),ans);
			}
		}
		if(ans==(int)1e9)cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}
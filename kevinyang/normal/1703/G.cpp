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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1]+arr[i];
		}
		int ans = 0;
		for(int i = 1; i<=n; i++){
			int cnt = 0;
			for(int j = i; j<=n; j++){
				int dif = j-i+1;
				if(dif>=40)break;
				cnt+=arr[j]/(1LL<<dif);
			}
			//cout << i << " " << cnt << "\n";
			cnt+=psa[i-1];
			cnt-=(i-1)*k;
			ans = max(ans,cnt);
		}
		ans = max(psa[n]-n*k,ans);
		cout << ans << "\n";
	}
	return 0;
}
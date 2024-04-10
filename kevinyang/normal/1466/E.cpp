#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n);
		vector<int>freq(62);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<62; i++){
			for(int j = 0; j<n; j++){
				if(arr[j]&(1LL<<i)){
					freq[i]++;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i<n; i++){
			int btand = 0;
			for(int j = 0; j<62; j++){
				if(arr[i]&(1LL<<j)){
					btand+=(1LL<<j)%mod*freq[j]%mod; btand%=mod;
				}
			}
			int btor = arr[i]%mod*n%mod;
			for(int j = 0; j<62; j++){
				if((arr[i]&(1LL<<j))==0){
					btor+=(1LL<<j)%mod*freq[j]%mod; btor%=mod;
				}
			}
			ans+=btor*btand%mod;
			ans%=mod;
		}
		cout << ans << "\n";
	}
	return 0;
}
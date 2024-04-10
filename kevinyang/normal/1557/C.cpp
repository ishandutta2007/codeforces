#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		if(n%2==1){
			int ans = 1;
			for(int i = 1; i<=k; i++){
				ans*=(modpow(2,n-1)+1);
				ans%=mod;
			}
			cout << ans << "\n";
		}
		else{
			int ans = 0;
			for(int i = 1; i<=k; i++){
				int v = modpow(2,n-1)+mod-1;
				v%=mod;
				int v2 = modpow(v,i-1);
				int v3 = modpow(modpow(2,n),k-i);
				ans+=v2*v3%mod;
				ans%=mod;
			}
			int v = modpow(2,n-1)+mod-1;
			v%=mod;
			int v2 = modpow(v,k);
			ans+=v2;
			ans%=mod;
			cout << ans << "\n";
		}
	}
	return 0;
}
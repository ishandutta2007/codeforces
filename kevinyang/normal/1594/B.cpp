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
		int ans = 0;
		for(int i = 0; i<30; i++){
			if(k&(1<<i)){
				ans+=modpow(n,i);
				ans%=mod;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
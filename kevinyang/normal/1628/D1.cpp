#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = (int)1e9+7;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int choose(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[y]%mod)*inv[x-y]%mod;
}
int permute(int x, int y){
	if(y>x)return 0;
	return (fact[x]*inv[x-y])%mod;
}
void precalc(){
	fact[0] = 1; inv[0] = 1;
	for(int i = 1; i<=2000000; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[2000000] = modpow(fact[2000000],mod-2);
	for(int i = 1999999; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		if(n==m){
			cout << m*k%mod << "\n";
			continue;
		}
		int ans = 0;
		int inv2 = modpow(2,mod-2);
		for(int i = 1; i<=m; i++){
			int v = choose(n-i-1,m-i);
			v%=mod;
			//cout << v << "\n";
			v*=modpow(inv2,n-i);
			v%=mod;
			v*=i;
			v%=mod;
			v*=k;
			v%=mod;
			ans+=v;
			ans%=mod;
		}
		cout << ans << "\n";
	}
	return 0;
}
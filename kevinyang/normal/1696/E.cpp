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
	int n;
	cin >> n;
	vector<int>arr(n+2);
	for(int i = 1; i<=n+1; i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 1; i<=n+1; i++){
		ans+=choose(i-1+arr[i]-1+1,i);
		ans%=mod;
		//cout << i << " " << i-1+arr[i]-1+1 << " " << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}
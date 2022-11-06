#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = (int)998244353;
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
	int n,k;
	cin >> n >> k;
	if(k==0){
		cout << fact[n] << "\n";
		return 0;
	}
	if(k>=n){
		cout << "0\n";
		return 0;
	}
	int ans = 0;
	//cerr << "nae\n";
	for(int i = n-k; i>=1; i--){
		int v = choose(n,n-k)*choose(n-k,i)%mod*modpow(i,n)%mod;
		if(i%2==(n-k)%2)ans+=v;
		else ans-=v;
		ans+=mod; ans%=mod;
	}
	cout << ans*2%mod << "\n";
	return 0;
}
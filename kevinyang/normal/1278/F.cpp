#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(2000010);
vector<int>inv(2000010);
const int mod = 998244353;
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
vector<int>mat(5005);
int choose2(int x, int y){
	int ans = 1;
	for(int i = 0; i<y; i++){
		ans*=x-i;
		ans%=mod;
		ans*=mat[i+1];
		ans%=mod;
	}
	return ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n,m,k;
	cin >> n >> m >> k;
	int ans = 0;
	int p = modpow(m,mod-2);
	int invp = 1+mod-p;
	invp%=mod;
	for(int i = 1; i<=5000; i++){
		mat[i] = modpow(i,mod-2);
	}
	for(int i = 1; i<=min(n,k); i++){
		
		int cnt = 0;
		for(int j = 1; j<=i; j++){
			int v = choose(i,i-j)*modpow(i-j,k)%mod;
			if(j%2==1)cnt+=v;
			else cnt+=mod-v;
			cnt%=mod;
		}
		cnt = modpow(i,k)+mod-cnt;
		cnt%=mod;
		//cout << cnt << " ";
		int prob = choose2(n,i)*modpow(p,i)%mod*cnt%mod;
		ans+=prob;
		ans%=mod;
		//cout << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}
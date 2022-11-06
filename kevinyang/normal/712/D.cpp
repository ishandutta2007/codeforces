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
	if(y>x||x<0||y<0)return 0;
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
	int a,b,k,t;
	cin >> a >> b >> k >> t;
	//cerr << "nae\n";
	vector<int>dp(300001);
	int exp2 = 2*k+1;
	int mn = min(a,b);
	a-=mn; b-=mn;
	for(int i = 0; i<=300000; i++){
		int add = 1;
		for(int j = 0; j<=t; j++){
			int den = i-j*exp2;
			int num = t+den-1;
			if(add)dp[i]+=choose(t,j)*choose(num,den)%mod;
			else dp[i]-=choose(t,j)*choose(num,den)%mod;
			dp[i]+=mod; dp[i]%=mod;
			add^=1;
		}
		//if(i%1000==0)cerr << "nae2\n";
	}
	vector<int>psa(300001);
	psa[0] = dp[0];
	for(int i = 1; i<=300000; i++){
		psa[i] = psa[i-1]+dp[i];
		psa[i]%=mod;
	}
	//cerr << "nae\n";
	int ans = 0;
	if(a==0){
		for(int i = b+1; i<=2*k*t; i++){
			ans+=psa[i-b-1]*dp[i]%mod;
			ans%=mod;
		}
	}
	else{
		assert(b==0);
		for(int i = 0; i<=2*k*t; i++){
			if(a+i>2*k*t){
				ans+=dp[i]*psa[2*k*t]%mod;
				ans%=mod;
			}
			else{
				ans+=dp[i]*psa[i+a-1]%mod;
				ans%=mod;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
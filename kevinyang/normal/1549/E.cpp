#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>fact(6000010);
vector<int>inv(6000010);
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
	for(int i = 1; i<=6000000; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[6000000] = modpow(fact[6000000],mod-2);
	for(int i = 5999999; i>0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n,q;
	cin >> n >> q;
	vector<vector<int>>dp(3*n+1,vector<int>(3));
	dp[0][0] = dp[0][1] = dp[0][2] = n+1;
	int inv3 = modpow(3,mod-2);
	for(int i = 1; i<=3*n; i++){
		int x = (choose(3*n+3,i+1)-dp[i-1][0]*2-dp[i-1][1]);
		x%=mod; x+=mod; x%=mod;
		x*=inv3; x%=mod;
		dp[i][0] = x;
		dp[i][1] = dp[i][0]+dp[i-1][0]; dp[i][1]%=mod;
		dp[i][2] = dp[i][1]+dp[i-1][1]; dp[i][2]%=mod;
	}
	while(q--){
		int x;
		cin >> x;
		cout << dp[x][0] << "\n";
	}
	return 0;
}
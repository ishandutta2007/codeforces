#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 0;
int modpow(int x, int y){
	return !y?1:(y%2==1?x:1)*modpow(x*x%mod,y/2)%mod;
}
vector<int>fact(1000001);
vector<int>inv(1000001);
void precalc(){
	fact[0] = 1;
	for(int i = 1; i<=1000000; i++){
		fact[i] = fact[i-1]*i%mod;
	}
	inv[1000000] = modpow(fact[1000000],mod-2);
	for(int i = 999999; i>=0; i--){
		inv[i] = inv[i+1]*(i+1)%mod;
	}
}
int choose(int x, int y){
	if(y>x)return 0;
	return fact[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m; mod = m;
	precalc();
	vector<int>powers(1000); powers[0] = 1;
	for(int i = 1; i<1000; i++){
		powers[i] = powers[i-1]*2; powers[i]%=m;
	}
	vector<vector<int>>dp(n+1,vector<int>(n+1));//#ways up to i with currently choosing j things to turn on
	dp[1][1] = 1; dp[2][2] = 2;
	for(int i = 3; i<=n; i++){
		for(int j = 1; j<i-1; j++){
			for(int k = 1; k<=n; k++){
				int idx = i-j-1;
				if(j+k<=n){
					dp[i][j+k]+=powers[j-1]*dp[idx][k]%m*choose(j+k,k)%m;
					dp[i][j+k]%=m;
				}
			}
		}
		dp[i][i] = powers[i-1];
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans+=dp[n][i]; ans%=mod;
	}
	cout << ans << "\n";
	return 0;
}
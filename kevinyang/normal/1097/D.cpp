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
vector<vector<int>>dp(69,vector<int>(69));
vector<vector<int>>dp2(69,vector<int>(69));
vector<vector<int>>psa(69,vector<int>(69));
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n,k;
	cin >> n >> k;
	map<int,int>hm;
	set<int>s;
	if(true){
		int v = n;
		for(int i = 2; i*i<=n; i++){
			while(v%i==0){
				v/=i;
				s.insert(i);
				hm[i]++;
			}
		}
		if(v>1){
			s.insert(v);
			hm[v]++;
		}
	}
	vector<int>factors;
	for(int i = 1; i*i<=n; i++){
		if(i*i==n){
			factors.push_back(i);
		}
		else if(n%i==0){
			factors.push_back(i);
			factors.push_back(n/i);
		}
	}
	vector<int>invs(100);
	for(int i = 1; i<100; i++){
		inv[i] = modpow(i,mod-2);
	}
	for(int u = 1; u<=60; u++){
		dp[u][u] = 1;
	}
	for(int t = 1; t<=k; t++){
		for(int u = 1; u<=60; u++){
			for(int j = 0; j<=60; j++){
				dp2[u][j] = dp[u][j]*inv[j+1];
				dp2[u][j]%=mod;
			}
			for(int j = 60; j>=0; j--){
				dp2[u][j]+=dp2[u][j+1];
				dp2[u][j]%=mod;
			}
		}
		for(int u = 1; u<=60; u++){
			for(int j = 0; j<=60; j++){
				dp[u][j] = dp2[u][j];
				dp2[u][j] = 0;
			}
		}
	}
	//cout << dp[1][0] << "\n";
	//cout << dp[1][1] << "\n";
	int ans = 0;
	for(int nxt: factors){
		int val = nxt;
		int prob = 1;
		for(int pf: s){
			int cnt = 0;
			while(val%pf==0){
				val/=pf;
				cnt++;
			}
			prob*=dp[hm[pf]][cnt];
			prob%=mod;
		}
		//cout << prob << "\n";
		prob*=(nxt%mod);
		prob%=mod;
		ans+=prob;
		ans%=mod;
	}
	cout << ans << "\n";
	return 0;
}
/*
stars and bars on prime factorization exponents somehow ???

stars and bars doesn't work directly because of different possiblities during intermediate states

do dp since the exponent of the primes are very low because it's O(logn)

quadratic dp???



*/
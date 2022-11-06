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
bool isprime(int x){
	if(x<=1)return false;
	for(int i = 2; i*i<=x; i++){
		if(x%i==0)return false;
	}
	return true;
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>pfs = {4,9,16,25,36,49,64};
	for(int i = 1; i<=n; i++){
		for(int nxt: pfs){
			while(arr[i]%nxt==0){
				arr[i]/=nxt;
			}
		}
	}
	vector<int>pf;
	for(int i = 1; i<=70; i++){
		if(isprime(i)){
			pf.push_back(i);
		}
	}
	vector<int>val(100);
	for(int i = 0; i<19; i++){
		val[pf[i]] = (1<<i);
	}
	vector<int>a(100);
	for(int i = 1; i<=70; i++){
		int cur = 0;
		for(int j = 2; j<=70; j++){
			if(isprime(j)&&i%j==0){
				cur^=val[j];
			}
		}
		a[i] = cur;
	}
	int cur = 0;
	vector<int>freq(100);
	for(int i = 1; i<=n; i++){
		freq[arr[i]]++;
	}
	vector<int>dp(1<<20);
	vector<int>dp2(1<<20);
	dp[0] = 1;
	for(int j = 1; j<=70; j++){
		int odd = 0; int even = 0;
		if(freq[j]==0){
			even = 1;
		}
		else{
			odd = modpow(2,freq[j]-1);
			even = modpow(2,freq[j]-1);
		}
		int v = a[j];
		for(int i = 0; i<(1<<20); i++){
			dp2[i] = dp[i^v]*odd+dp[i]*even;
			dp2[i]%=mod;
		}
		for(int i = 0; i<(1<<20); i++){
			dp[i] = dp2[i];
		}
	}
	dp[0]+=mod-1;
	dp[0]%=mod;
	cout << dp[0] << "\n";
	return 0;
}
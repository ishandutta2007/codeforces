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
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false); precalc();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int odd = 0; int even = 0;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>odds;
		odds.push_back(0);
		vector<int>evens;
		evens.push_back(0);
		vector<vector<int>>freq(2,vector<int>(11));
		for(int i = 1; i<=n; i++){
			string s = to_string(arr[i]);
			freq[(int)s.size()%2][arr[i]%11]++;
			if((int)s.size()%2==0){
				even++;
				evens.push_back(arr[i]%11);
			}
			else{
				odd++;
				odds.push_back(arr[i]%11);
			}
		}
		if(odd==0){
			int sum = 0;
			for(int i = 1; i<=n; i++){
				sum+=arr[i];
			}
			sum%=11;
			if(sum==0){
				cout << fact[n] << "\n";
			}
			else{
				cout << "0\n";
			}
			continue;
		}
		vector<vector<vector<int>>>dp(odd+1,vector<vector<int>>(odd+1,vector<int>(11)));
		vector<vector<vector<int>>>dp2(even+1,vector<vector<int>>(even+1,vector<int>(11)));
		dp[0][0][0] = 1;
		for(int i = 1; i<=odd; i++){
			for(int j = 0; j<odd; j++){
				for(int k = 0; k<11; k++){
					dp[i][j+1][(k+odds[i])%11]+=dp[i-1][j][k];
					dp[i][j+1][(k+odds[i])%11]%=mod;
					dp[i][j][(k+11-odds[i])%11]+=dp[i-1][j][k];
					dp[i][j][(k+11-odds[i])%11]%=mod;
				}
			}
		}
		dp2[0][0][0] = 1;
		
		for(int i = 1; i<=even; i++){
			for(int j = 0; j<even; j++){
				for(int k = 0; k<11; k++){
					dp2[i][j+1][(k+evens[i])%11]+=dp2[i-1][j][k];
					dp2[i][j+1][(k+evens[i])%11]%=mod;
					dp2[i][j][(k+11-evens[i])%11]+=dp2[i-1][j][k];
					dp2[i][j][(k+11-evens[i])%11]%=mod;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i<=even; i++){
			for(int k = 0; k<11; k++){
				int val = dp2[even][i][k]*dp[odd][(odd+1)/2][(11-k)%11]%mod;
				val*=choose(i+odd/2+1-1,odd/2+1-1); val%=mod;
				val*=fact[i]; val%=mod;
				val*=choose(even-i+(odd+1)/2-1,(odd+1)/2-1); val%=mod;
				val*=fact[even-i]; val%=mod;
				val*=fact[odd/2]; val%=mod;
				val*=fact[(odd+1)/2]; val%=mod;
				ans+=val; ans%=mod;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
two properties for a number
property 1 is the parity of length of the original number
even length doesn't affect anything on the other numbers 
odd length changes sign on the numbers in front of it in decimal notation

property 2 is the modulo 11 value 
do dp on this 
like n^2 * 11
or something 
idk

how to do dp on odd positioning 


*/
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
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>freq(n+1);
	for(int i = 1; i<=n; i++){
		freq[arr[i]]++;
	}
	set<int>s;
	for(int i = 1; i<=n; i++){
		s.insert(arr[i]);
	}
	vector<int>a; a.push_back(0);
	for(int nxt: s)a.push_back(nxt);
	cout << "\n";
	int ans = 0;
	vector<vector<int>>dp(n+1,vector<int>(n+1));
	dp[0][0] = 1;
	for(int i = 1; i<a.size(); i++){
		for(int j = 0; j<=i; j++){
			dp[i][j]+=dp[i-1][j]; dp[i][j]%=mod;
			if(j)dp[i][j]+=dp[i-1][j-1]*freq[a[i]]%mod; 
			dp[i][j]%=mod;
			if(j&&freq[a[i]]>1){
				int total = permute(n,j+1);
				int num = freq[a[i]]-1; num*=dp[i-1][j-1]*freq[a[i]]%mod; num%=mod;
				int prob = num*modpow(total,mod-2); prob%=mod;
				ans+=prob; ans%=mod;
			}
			//cout << i << " " << j << " " << ans << "\n";
		}
	}
	cout << ans << "\n";
	return 0;
}
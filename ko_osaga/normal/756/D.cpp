#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n;
lint dp[5005][5005];
lint fact[5005], invf[5005];

lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret % mod;
}


lint bino(int x, int y){
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

int nxt[5005][26];
char str[5005];

int main(){
	cin >> n >> str;
	fact[0] = invf[0] = 1;
	for(int i=1; i<=n; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	for(int i=0; i<26; i++) nxt[n][i] = n;
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<26; j++){
			if(j + 'a' == str[i]){
				nxt[i][j] = i;
			}
			else nxt[i][j] = nxt[i+1][j];
		}
	}
	for(int i=0; i<n; i++) dp[1][i] = 1;
	for(int i=2; i<=n; i++){
		lint sum = 0;
		for(int j=n-1; j>=0; j--){
			dp[i][j] = sum;
			if(nxt[j+1][str[j] - 'a'] < n){
				dp[i][j] += mod - dp[i-1][nxt[j+1][str[j] - 'a']];
			}
			dp[i][j] %= mod;
			sum += dp[i-1][j];
			if(nxt[j+1][str[j] - 'a'] < n){
				sum += mod - dp[i-1][nxt[j+1][str[j] - 'a']];
			}
			sum %= mod;
		}
	}
	int ret = 0;
	for(int i=1; i<=n; i++){
		int cur = 0;
		for(int j=0; j<26; j++){
			cur += dp[i][nxt[0][j]];
			cur %= mod;
		}
		ret += 1ll * bino(n-1, i-1) * cur % mod;
		ret %= mod;
	}
	cout << ret;
}
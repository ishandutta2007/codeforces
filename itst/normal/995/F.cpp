#include<bits/stdc++.h>
using namespace std;

const int _ = 3003 , MOD = 1e9 + 7;
int N , D , dp[_][_] , jc[_] , inv[_] , pre[_] , suf[_]; vector < int > nxt[_];

int poww(long long a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = tms * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return tms;
}

void dfs(int x){
	for(int i = 1 ; i <= N + 1 ; ++i) dp[x][i] = 1;
	for(auto t : nxt[x]){dfs(t); for(int i = 1 ; i <= N + 1 ; ++i) dp[x][i] = 1ll * dp[x][i] * dp[t][i] % MOD;}
	for(int i = 1 ; i <= N + 1 ; ++i) dp[x][i] = (dp[x][i] + dp[x][i - 1]) % MOD;
}

int main(){
	cin >> N >> D; for(int i = 2 , x ; i <= N ; ++i){cin >> x; nxt[x].push_back(i);}
	dfs(1); jc[0] = 1; for(int i = 1 ; i <= N + 1 ; ++i) jc[i] = 1ll * jc[i - 1] * i % MOD;
	inv[N + 1] = poww(jc[N + 1] , MOD - 2) % MOD; for(int i = N ; ~i ; --i) inv[i] = inv[i + 1] * (i + 1ll) % MOD;
	for(int i = 1 ; i <= N + 1 ; ++i) pre[i] = suf[i] = D - i;
	int sum = 0; pre[0] = suf[N + 2] = 1;
	for(int i = 1 ; i <= N + 1 ; ++i) pre[i] = 1ll * pre[i] * pre[i - 1] % MOD;
	for(int i = N + 1 ; i ; --i) suf[i] = 1ll * suf[i + 1] * suf[i] % MOD;
	for(int i = 1 ; i <= N + 1 ; ++i)
		sum = (sum + ((N - i + 1) & 1 ? -1ll : 1ll) * pre[i - 1] * suf[i + 1] % MOD * inv[i - 1] % MOD * inv[N - i + 1] % MOD * dp[1][i] % MOD) % MOD;
	cout << (sum + MOD) % MOD;
	return 0;
}
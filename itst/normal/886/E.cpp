#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7 , MOD = 1e9 + 7;
int jc[_] , inv[_] , dp[_] , N , K;

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

int main(){
	cin >> N >> K;
	jc[0] = 1; for(int i = 1 ; i <= N ; ++i) jc[i] = 1ll * jc[i - 1] * i % MOD;
	inv[N] = poww(jc[N] , MOD - 2); for(int i = N - 1 ; ~i ; --i) inv[i] = inv[i + 1] * (i + 1ll) % MOD;
	int sum = 0 , val = 0;
	for(int i = K + 2 ; i <= N ; ++i){
		val = (val + 1ll * dp[i - 1] * inv[i - 2] - 1ll * dp[i - K - 1] * inv[i - K - 2] % MOD + MOD) % MOD;
		dp[i] = (1ll * val * jc[i - 2] + 1ll * jc[i - 2] * (i - K - 1)) % MOD;
		sum = (sum + 1ll * dp[i] * jc[N - 1] % MOD * inv[i - 1]) % MOD;
	}
	cout << sum; return 0;
}
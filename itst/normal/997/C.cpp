#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353 , MAXN = 1e6 + 7;
int jc[MAXN] , inv[MAXN] , N;

inline int poww(int a , int b){
	a %= MOD;
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

void init(){
	jc[0] = 1;
	for(int i = 1 ; i <= 1e6 ; ++i)
		jc[i] = jc[i - 1] * i % MOD;
	inv[1000000] = poww(jc[1000000] , MOD - 2);
	for(int i = 1e6 - 1 ; i >= 0 ; --i)
		inv[i] = inv[i + 1] * (i + 1) % MOD;
}

inline int C(int b , int a){return jc[b] * inv[a] % MOD * inv[b - a] % MOD;}

signed main(){
	init();
	cin >> N;
	int ans = (poww(3 , N * N) - poww(poww(3 , N) + MOD - 3 , N) + MOD) % MOD;
	for(int i = 1 ; i <= N ; ++i)
		ans = (ans - (i & 1 ? -1 : 1) * C(N , i) * ((3 * poww(poww(3 , N - i) + MOD - 1 , N) + (poww(3 , i) + MOD - 3) * poww(3 , N * (N - i))) % MOD) % MOD + MOD) % MOD;
	cout << ans;
	return 0;
}
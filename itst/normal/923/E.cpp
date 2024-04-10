#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 1 << 18 , MOD = 998244353 , G = 3;
int dir[_] , need , invnd , N , K , P[_] , F[_] , jc[_] , inv[_];

int poww(int a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = tms * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return tms;
}

void init(int len){
	need = 1; while(need < len) need <<= 1;
	invnd = poww(need , MOD - 2);
	for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
}

void NTT(int *arr , int tp){
	for(int i = 1 ; i < need ; ++i)
		if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 , wn = poww(G , MOD / 2 / i) ; j < need ; j += i << 1){
			for(int k = 0 , w = 1 ; k < i ; ++k , w = w * wn % MOD){
				int x = arr[j + k] , y = w * arr[i + j + k] % MOD;
				arr[j + k] = (x + y) % MOD; arr[i + j + k] = (x - y + MOD) % MOD;
			}
	}
	if(tp == -1){reverse(arr + 1 , arr + need); for(int i = 0 ; i < need ; ++i) arr[i] = arr[i] * invnd % MOD;}
}

signed main(){
	cin >> N >> K; for(int i = 0 ; i <= N ; ++i) cin >> P[i];
	jc[0] = 1; for(int i = 1 ; i <= N ; ++i) jc[i] = jc[i - 1] * i % MOD;
	inv[N] = poww(jc[N] , MOD - 2); for(int i = N - 1 ; ~i ; --i) inv[i] = inv[i + 1] * (i + 1) % MOD;
	for(int i = 0 ; i <= N ; ++i){P[i] = P[i] * jc[i] % MOD; F[i] = inv[i];}
	init(2 * N + 1); reverse(F , F + N + 1); NTT(P , 1); NTT(F , 1);
	for(int i = 0 ; i < need ; ++i) F[i] = F[i] * P[i] % MOD;
	NTT(F , -1); memset(P , 0 , sizeof(P));
	for(int i = N ; i < need ; ++i){if(i - N <= N) F[i - N] = F[i]; F[i] = 0;}
	for(int i = 0 ; i <= N ; ++i){F[i] = F[i] * poww(poww(i + 1 , MOD - 2) , K) % MOD; P[i] = (i & 1 ? MOD - 1 : 1) * inv[i] % MOD;}
	reverse(P , P + N + 1); NTT(F , 1); NTT(P , 1);
	for(int i = 0 ; i < need ; ++i) F[i] = F[i] * P[i] % MOD;
	NTT(F , -1); for(int i = N ; i <= 2 * N ; ++i) printf("%lld\n" , F[i] * inv[i - N] % MOD);
	return 0;
}
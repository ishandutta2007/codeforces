#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

const int MOD = 1e9 + 7 , INV2 = 5e8 + 4;
int S[5007][5007] , N , K;

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N >> K;
	S[1][1] = 1;
	for(int i = 2 ; i <= K ; ++i)
		for(int j = 1 ; j <= K ; ++j)
			S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % MOD;
	long long fac = 1 , binom = 1 , pow2 = poww(2 , N) , ans = 0;
	for(int i = 1 ; i <= K ; ++i){
		binom = binom * (N - i + 1) % MOD * poww(i , MOD - 2) % MOD;
		pow2 = pow2 * INV2 % MOD;
		fac = fac * i % MOD;
		ans = (ans + S[K][i] * fac % MOD * binom % MOD * pow2 % MOD) % MOD;
	}
	cout << ans;
	return 0;
}
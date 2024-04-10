#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int sl[1503][1503] , sr[1503][1503] , invalid[1503] , prob[100003] , N , M , A , B , K;

int poww(int a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = 1ll * tms * a % MOD;
		a = 1ll * a * a % MOD; b >>= 1;
	}
	return tms;
}

signed main(){
	scanf("%d %d %d %d %d" , &N , &M , &A , &B , &K);
	if(A == B){printf("%d\n" , M - 2 * K > 0); return 0;}
	sl[0][0] = sr[0][0] = 1; A = 1ll * A * poww(B , MOD - 2) % MOD; B = MOD + 1 - A; prob[0] = poww(B , K);
	for(int i = 1 ; i <= K ; ++i)
		prob[i] = 1ll * prob[i - 1] * A % MOD * poww(B , MOD - 2) % MOD * (K - i + 1) % MOD * poww(i , MOD - 2) % MOD;
	for(int i = 1 ; i <= N ; ++i){
		static int s1[1503] , s2[1503];
		for(int j = 0 ; j < M ; ++j){
			s1[j] = ((j ? s1[j - 1] : 0) + prob[j]) % MOD;
			s2[j] = ((j ? s2[j - 1] : 0) - 1ll * prob[j] * sl[i - 1][M - j] % MOD + MOD) % MOD;
		}
		for(int j = M - 1 ; ~j ; --j)
			sl[i][j] = (sl[i][j + 1] + prob[j] * (s1[M - j - 1] * (1ll + 2 * MOD - invalid[i - 1] - sr[i - 1][M - j]) % MOD
												  + s2[M - j - 1])) % MOD;
		for(int j = 0 ; j < M ; ++j){
			s1[j] = ((j ? s1[j - 1] : 0) + prob[j]) % MOD;
			s2[j] = ((j ? s2[j - 1] : 0) - 1ll * prob[j] * sr[i - 1][M - j] % MOD + MOD) % MOD;
		}
		for(int j = M - 1 ; ~j ; --j)
			sr[i][j] = (sr[i][j + 1] + prob[j] * (s1[M - j - 1] * (1ll + 2 * MOD - invalid[i - 1] - sl[i - 1][M - j]) % MOD
												  + s2[M - j - 1])) % MOD;
		invalid[i] = (MOD + 1 - sl[i][0]) % MOD;
	}
	cout << (MOD + 1 - invalid[N]) % MOD; return 0;
}
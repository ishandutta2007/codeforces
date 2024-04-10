#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int dp1[3003] , dp2[3003]; char S[3003] , T[3003]; int N , M , ans;
  
int main(){
	scanf("%s %s" , S + 1 , T + 1); N = strlen(S + 1); M = strlen(T + 1);
	for(int i = N ; i > 1 ; --i){
		dp1[M] = dp1[M] * 2 % MOD;
		for(int j = M - 1 ; j ; --j) if(S[i] == T[j + 1]) dp1[j + 1] = (dp1[j + 1] + dp1[j]) % MOD;
		if(S[i] == T[1]) dp1[1] += N - i + 1;
	}

	if(M == 1) ans += S[1] == T[1] ? N : 0;
	else{
		for(int i = 1 ; i <= M ; ++i) if(S[1] == T[i]) dp2[i] = 1;
		for(int j = 2 ; j <= N ; ++j){
			for(int k = 1 ; k <= M ; ++k){
				if(k != 1 && T[k - 1] == S[j]) dp2[k - 1] = (dp2[k - 1] + dp2[k]) % MOD;
				if(k + j - 1 <= M && T[k + j - 1] != S[j]) dp2[k] = 0;
			}
			if(j >= M) ans = (ans + dp2[1]) % MOD;
		}
	}
	cout << (ans + dp1[M]) * 2ll % MOD;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int C[5103][5103] , S , R , P , inv[5003];

int poww(int a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = 1ll * tms * a % MOD;
		a = 1ll * a * a % MOD; b >>= 1;
	}
	return tms;
}

int calc(int p , int s , int l){
	if(!p) return !s;
	int sum = 0;
	for(int j = 0 ; j <= p && j * l <= s ; ++j)
		sum = (sum + (j & 1 ? MOD - 1ll : 1ll) * C[p][j] % MOD * C[s - j * l + p - 1][p - 1]) % MOD;
	return sum;
}

int main(){
	cin >> P >> S >> R;
	for(int i = 0 ; i <= S + P ; ++i){
		C[i][0] = 1;
		for(int j = 1 ; j <= i ; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	inv[1] = 1; for(int i = 2 ; i <= P ; ++i) inv[i] = MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD;
	int sum = 0;
	for(int i = R ; i <= S ; ++i)
		for(int j = 1 ; j * i <= S && j <= P ; ++j)
			sum = (sum + 1ll * calc(P - j , S - j * i , i) * C[P - 1][j - 1] % MOD * inv[j]) % MOD;
	cout << 1ll * sum * poww(C[S - R + P - 1][P - 1] , MOD - 2) % MOD;
	return 0;
}
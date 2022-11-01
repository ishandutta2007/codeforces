#include<bits/stdc++.h>
#define int long long
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

const int MOD = 1e9 + 7;
int dp[50][10010] , inv[52];

inline int poww(int a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

signed main(){
	for(int i = 1 ; i <= 51 ; ++i)
		inv[i] = poww(i , MOD - 2);
	int N = read() , K = read() , ans = 1;
	for(int i = 2 ; i * i <= N ; ++i)
		if(N % i == 0){
			int cnt = 0;
			while(N % i == 0){
				++cnt;
				N /= i;
			}
			dp[0][0] = 1;
			int tms = i;
			for(int j = 1 ; j <= cnt ; ++j , tms = tms * i % MOD)
				dp[j][0] = (dp[j - 1][0] + tms) % MOD;
			for(int j = 1 ; j <= K ; ++j){
				dp[0][j] = 1;
				for(int k = 1 ; k <= cnt ; ++k)
					dp[k][j] = (dp[k][j - 1] * inv[k + 1] + dp[k - 1][j]) % MOD;
			}
			ans = ans * (dp[cnt][K] - dp[cnt - 1][K] + MOD) % MOD;
		}
	if(N != 1)
		ans = ans * ((poww(poww(2 , K) , MOD - 2) * (N % MOD) + MOD + 1 - (poww(poww(2 , K) , MOD - 2))) % MOD) % MOD;
	cout << ans;
	return 0;
}
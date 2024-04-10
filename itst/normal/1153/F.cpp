#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

const int MOD = 998244353;
int N , L , K , dp[4007][2007][2];

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

int jc(int x){
	int times = 1;
	for(int i = 2 ; i <= x ; ++i)
		times = 1ll * times * i % MOD;
	return times;
}

void add(int &a , int b){
	a += b; if(a >= MOD) a -= MOD;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N >> K >> L;
	dp[0][0][0] = 1;
	for(int i = 0 ; i < 2 * N + 1 ; ++i)
		for(int j = 0 ; j <= N ; ++j)
			for(int k = 0 ; k <= 1 ; ++k)
				if(dp[i][j][k]){
					if(k == 0 && j >= K)
						add(dp[i + 1][j][1] , dp[i][j][0]);
					add(dp[i + 1][j + 1][k] , dp[i][j][k]);
					if(j)
						add(dp[i + 1][j - 1][k] , 1ll * dp[i][j][k] * j % MOD);
				}
	cout << 1ll * dp[2 * N + 1][0][1] * poww(2 , N) % MOD * jc(N) % MOD * poww(jc(2 * N + 1) , MOD - 2) % MOD * L % MOD;
	return 0;
}
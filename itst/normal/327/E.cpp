#include<bits/stdc++.h>
#define lowbit(i) (i & -i)
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
int dp[1 << 24] , sum[1 << 24] , card[24] , num[2] , logg2[1 << 24] , N , M;

int main(){
	N = read();
	for(int i = 0 ; i < N ; ++i)
		card[i] = read();
	logg2[0] = -1;
	for(int i = 1 ; i < 1 << N ; ++i){
		logg2[i] = logg2[i >> 1] + 1;
		sum[i] = sum[i - lowbit(i)] + card[logg2[lowbit(i)]];
	}
	M = read();
	for(int i = 0 ; i < M ; ++i)
		num[i] = read();
	dp[0] = 1;
	for(int i = 0 ; i < (1 << N) - 1 ; ++i){
		if((sum[i] == num[1] || sum[i] == num[0]) && sum[i])
			continue;
		int t = (1 << N) - 1 - i;
		while(t){
			dp[i | lowbit(t)] = dp[i | lowbit(t)] + dp[i] >= MOD ? dp[i | lowbit(t)] + dp[i] - MOD : dp[i | lowbit(t)] + dp[i];
			t -= lowbit(t);
		}
	}
	if(sum[(1 << N) - 1] == num[1] || sum[(1 << N) - 1] == num[0])
		cout << 0;
	else
		cout << dp[(1 << N) - 1];
	return 0;
}
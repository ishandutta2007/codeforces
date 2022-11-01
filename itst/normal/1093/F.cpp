#include<bits/stdc++.h>
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
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e5 + 10 , MOD = 998244353;
int num[MAXN] , len[MAXN][110] , dp[MAXN][110] , N , K , L;

void input(){
	N = read();
	K = read();
	L = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
}

void init(){
	for(int i = 1 ; i <= N ; ++i)
		if(num[i] != -1)
			for(int j = 1 ; j <= K ; ++j)
				len[i][j] = j == num[i] ? len[i - 1][j] + 1 : 0;
		else
			for(int j = 1 ; j <= K ; ++j)
				len[i][j] = len[i - 1][j] + 1;
	dp[0][K + 1] = 1;
}

inline int add(int a , int b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

inline int Min(int a , int b){
	return a < b ? a + MOD - b : a - b;
}

void work(){
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= K ; ++j){
			if(len[i][j]){
				dp[i][j] = add(dp[i][j] , dp[i - 1][K + 1]);
				if(len[i][j] >= L)
					dp[i][j] = add(dp[i][j] , Min(Min(dp[i - L][j] , dp[i - L][j - 1]) , dp[i - L][K + 1]));
			}
			dp[i][j + 1] = dp[i][j];
		}
}

void output(){
	cout << dp[N][K];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	input();
	init();
	work();
	output();
	return 0;
}
#include<bits/stdc++.h>
#define ld long double
#define PDI pair < ld , int >
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

ld P[3010][310] , cur[310] , dp[2][310][3010] , ans;
int N , M;
priority_queue < PDI > q;

void input(){
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			P[i][j] = read() / 1000.0;
}

void init(){
	for(int i = 1 ; i <= M ; ++i){
		dp[1][i][0] = 1;
		for(int j = 1 ; j <= N ; ++j)
			dp[1][i][j] = dp[1][i][j - 1] * (1 - P[j][i]);
		q.push(PDI(-(cur[i] = dp[1][i][N]) , i));
	}
}

void work(){
	for(int i = 1 ; i <= N ; ++i){
		PDI t = q.top();
		q.pop();
		int x = t.second;
		ans += 1 + t.first;
		memcpy(dp[0][x] , dp[1][x] , sizeof(dp[0][x]));
		dp[1][x][0] = 0;
		for(int j = 1 ; j <= N ; ++j)
			dp[1][x][j] = dp[0][x][j - 1] * P[j][x] + dp[1][x][j - 1] * (1 - P[j][x]);
		q.push(PDI(-(cur[x] += dp[1][x][N]) , x));
	}
}

void output(){
	cout << fixed << setprecision(10) << ans;
}

int main(){
	input();
	init();
	work();
	output();
	return 0;
}
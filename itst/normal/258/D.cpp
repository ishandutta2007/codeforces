#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<vector>
#include<cmath>
#define ld long double
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

ld dp[1010][1010];
int num[1010] , N , M;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i - 1 ; j ; --j){
			dp[i][j] = num[i] > num[j];
			dp[j][i] = num[j] > num[i];
		}
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read();
		for(int j = 1 ; j <= N ; ++j)
			if(j != a && j != b){
				dp[j][a] = dp[j][b] = (dp[j][a] + dp[j][b]) * 0.5;
				dp[a][j] = dp[b][j] = (dp[a][j] + dp[b][j]) * 0.5;
			}
		dp[a][b] = dp[b][a] = (dp[a][b] + dp[b][a]) * 0.5;
	}
	ld sum = 0;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i - 1 ; j ; --j)
			sum += dp[j][i];
	cout << fixed << setprecision(8) << sum;
	return 0;
}
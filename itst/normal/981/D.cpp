#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define int long long
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

bool dp[51][51];
int sum[51] , N , K , base;

bool check(){
	memset(dp , 0 , sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= K ; ++j)
			for(int k = i - 1 ; k >= 0 ; --k)
				if(dp[k][j - 1] && ((sum[i] - sum[k]) & base) == base)
					dp[i][j] = 1;
	return dp[N][K];
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read(); K = read();
	for(int i = 1 ; i <= N ; ++i)
		sum[i] = read() + sum[i - 1];
	for(int i = 56 ; i >= 0 ; --i){
		base |= 1ll << i;
		if(!check()) base ^= 1ll << i;
	}
	printf("%lld" , base);
	return 0;
}
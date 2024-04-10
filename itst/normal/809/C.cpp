#include<iostream>
#include<cstdio>
#include<cstring>
//This code is written by Itst
using namespace std;

#define int long long
inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)){
	a = a * 10 + c - 48;
	c = getchar();
    }
    return a;
}

const int MOD = 1e9 + 7;
int dp[31][2][2][2] , cnt[31][2][2][2];

int work(int X , int Y , int Z){
    if(X < 0 || Y < 0) return 0;
    memset(dp , 0 , sizeof(dp)); memset(cnt , 0 , sizeof(cnt));
    for(int i = 0 ; i < 2 ; ++i)
	for(int j = 0 ; j < 2 ; ++j)
	    for(int k = 0 ; k < 2 ; ++k)
		for(int p = 0 ; p < 2 && (!i || (X & 1) || p < 1) ; ++p)
		    for(int q = 0 ; q < 2 && (!j || (Y & 1) || q < 1) ; ++q)
			if(!k || (p ^ q) <= (Z & 1)){
			    ++cnt[0][i][j][k];
			    dp[0][i][j][k] += p ^ q;
			}
    for(int t = 1 ; t <= 30 ; ++t)
	for(int i = 0 ; i < 2 ; ++i)
	    for(int j = 0 ; j < 2 ; ++j)
		for(int k = 0 ; k < 2 ; ++k)
		    for(int p = 0 ; p < 2 && (!i || (X & (1 << t)) || p < 1) ; ++p)
			for(int q = 0 ; q < 2 && (!j || (Y & (1 << t)) || q < 1) ; ++q)
			    if(!k || (p ^ q) <= ((Z >> t) & 1)){
				int I = i & !(((X >> t) & 1) ^ p) , J = j & !(((Y >> t) & 1) ^ q) , K = k & !(((Z >> t) & 1) ^ p ^ q);
				cnt[t][i][j][k] = (cnt[t][i][j][k] + cnt[t - 1][I][J][K]) % MOD;
				dp[t][i][j][k] = (dp[t][i][j][k] + dp[t - 1][I][J][K] + cnt[t - 1][I][J][K] * ((p ^ q) << t)) % MOD;
			    }
    return dp[30][1][1][1] + cnt[30][1][1][1];
}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
#endif
    for(int T = read() ; T ; --T){
	int X1 = read() - 1 , Y1 = read() - 1 , X2 = read() - 1 , Y2 = read() - 1 , K = read() - 1;
	printf("%lld\n" , ((work(X2 , Y2 , K) - work(X1 - 1 , Y2 , K) - work(X2 , Y1 - 1 , K) + work(X1 - 1 , Y1 - 1 , K)) % MOD + MOD) % MOD);
    }
    return 0;
}
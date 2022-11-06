//https://codeforces.com/contest/1268/problem/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}

const int N=300005;
int main(){
	int n,i,b;ll x=0ll,y=0ll;
	scanf("%d",&n);
	for(i=n;i   ;--i){
		scanf("%d",&b);
		if(i&1){x+=b>>1;y+=b-(b>>1);}
		else   {y+=b>>1;x+=b-(b>>1);}
	}
	printf("%lld",min(x,y));
	/*
	for(i=1;i<=n;++i)dp[i][0]=dp[i][1]=dp[i][2]=inf;
	dp[1][0]=0ll;
	for(i=1;i<=n;++i){
		b=a[i];
		++dp[i][1];
		++dp[i][2];
		for(x=0;x!=3;++x)for(y=0;y!=3;++y)if(!(x&y)){
			if((z=(x|y))==3)z=2;
			if(b>=z)cmax(dp[i+1][y],dp[i][x]+((b-z)>>1));
		}
//		printf("i=%d (%lld,%lld,%lld)\n",i,dp[i][0],dp[i][1],dp[i][2]);
	}
	printf("%lld",dp[n+1][0]);*/
	return 0;
}
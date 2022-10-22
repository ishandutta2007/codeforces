#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
const int N=210,M=10010;
int n,c,su;
double dp[N][M],ans,x;
signed main(){
	scanf("%d%lf",&n,&x),**dp=1;
	FOR(i,1,n){
		scanf("%d",&c),su+=c;
		ROF(j,i,1)ROF(k,su,c)dp[j][k]+=dp[j-1][k-c]*j/(n-j+1);
	}
	FOR(i,0,n-1)FOR(j,0,su){
		double a=n-i,b=su-j;
		ans+=min(b,x/2*(n+a))/a*dp[i][j];
	}
	printf("%.9lf",ans);
	return 0;
}
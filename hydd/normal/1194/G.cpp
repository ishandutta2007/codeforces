#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n,u,x,y,dp[110][20][16][16],numx[10],numy[10];
char s[110];
int solve(int d,int v,int s,int t,bool lim){
	if (v<-9||v>9) return 0;
	if (d==n+1) return (!v&&(s&t));
	if ((s&t)) s=1,t=1;
	if (!lim&&~dp[d][v+9][s][t]) return dp[d][v+9][s][t];
	int l=(lim?::s[d]-'0':9),res=0;
	for (int i=0;i<=9;i++)
		for (int j=0;j<=l;j++)
			res=(res+solve(d+1,v*10+i*y-j*x,s|numx[i],t|numy[j],lim&&(j==l)))%Mod;
	if (!lim) dp[d][v+9][s][t]=res; return res;
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	ll ans=0;
	//x==y
	for (int i=1;i<=n;i++) ans=(ans*10+(s[i]-'0'))%Mod;

	//x!=y
	for (x=1;x<=9;x++)
		for (y=x+1;y<=9;y++){
			if (__gcd(x,y)!=1) continue;
			memset(dp,-1,sizeof(dp));
			u=9/y;
			for (int i=0;i<=9;i++) numx[i]=0,numy[i]=0;
			for (int i=1;i<=u;i++) numx[x*i]=(1<<(i-1)),numy[y*i]=(1<<(i-1));
			ans=(ans+(solve(1,0,0,0,1)<<1))%Mod;
		}
	printf("%lld\n",ans);
	return 0;
}
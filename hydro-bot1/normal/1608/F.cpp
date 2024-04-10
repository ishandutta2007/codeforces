// Hydro submission #6324521644315469ab56dff7@1663550066245
#include<bits/stdc++.h>
using namespace std;
#define maxn 2009 
#define maxk 59
const long long mod=998244353;
int n,k,b[maxn];
int dp[2][maxn][maxn],f[maxn]; 
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return ;
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	int now=0,mmex=0;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		now^=1;
		for(int o=0;o<=i+1;o++)f[o]=0;
		for(int j=mmex;j<=min(i,b[i]+k);j++){
			for(int o=0;o<=i-j;o++){
				f[o]=1ll*f[o+1]*(o+1)%mod;
				if(j>mmex&&j-1<=b[i-1]+k)add(f[o],dp[now^1][j-1][o]);
				if(j>=b[i]-k){
					dp[now][j][o]=f[o];
					if(j<=b[i-1]+k&&j<i){
					if(o&&o+j-1<i)add(dp[now][j][o],dp[now^1][j][o-1]);
					if(o+j<i)add(dp[now][j][o],1ll*dp[now^1][j][o]*(j+o)%mod);
					}
				}
			}
		}
		mmex=max(mmex,b[i]-k);
	}
	int ans=0;
	for(int j=0;j<=n;j++)f[j]=0;
	for(int i=mmex;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			if(i<=b[n]+k)add(f[j],dp[now][i][j]);
			if(j)f[j-1]=1ll*f[j]*(n-i)%mod;
			else add(ans,f[j]);
		}
	}
	printf("%d",ans);
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}
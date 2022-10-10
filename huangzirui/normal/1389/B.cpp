#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,dp[maxn][11][2],a[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		int ans=0;
		n=read();m=read();k=read();
		for(i=1;i<=n;i++)a[i]=read();
		dp[1][0][0]=a[1];ans=max(ans,dp[1][0][0]);
		for(i=2;i<=n;i++)
			if(i-1<=m)dp[i][0][0]=dp[i-1][0][0]+a[i],ans=max(ans,dp[i][0][0]);
		for(j=1;j<=k;j++)
			for(i=1;i<n;i++)
				if(i+2*j-1<=m){
					dp[i][j][1]=dp[i+1][j-1][0]+a[i];
					dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])+a[i];
					ans=max(ans,max(dp[i][j][0],dp[i][j][1]));
				}
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
			for(j=1;j<=k;j++)
				dp[i][j][0]=dp[i][j][1]=0;
	}
	return 0;
}
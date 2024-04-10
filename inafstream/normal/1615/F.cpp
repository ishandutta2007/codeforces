#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

const int mod=1e9+7;

int n;
int f[2][4005],g[2][4005];
char s[2005],t[2005];

void solve()
{
	int i,j;
	scanf("%d",&n); 
	scanf("%s",s+1);
	scanf("%s",t+1);
	
	for(i=1;i<=n;i+=2)
	{
		if(s[i]!='?') s[i]^=1;
		if(t[i]!='?') t[i]^=1;
	}
	
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	int x=1,y=0;
	f[0][n]=1;
	
	rep(i,n)
	{
		swap(x,y);
		memset(f[y],0,sizeof(f[y]));
		memset(g[y],0,sizeof(g[y])); 
		for(j=0;j<=n+n;j++)
		{
			if(s[i]=='0'||s[i]=='?')
			{
				f[y][j]=(f[y][j]+f[x][j])%mod;
				g[y][j]=(g[y][j]+g[x][j])%mod;
			}
			if(s[i]=='1'||s[i]=='?')
			{
				f[y][j+1]=(f[y][j+1]+f[x][j])%mod;
				g[y][j+1]=(g[y][j+1]+g[x][j])%mod;
			}
		}
		
		swap(x,y);
		memset(f[y],0,sizeof(f[y]));
		memset(g[y],0,sizeof(g[y])); 
		for(j=1;j<=n+n;j++)
		{
			if(t[i]=='0'||t[i]=='?')
			{
				f[y][j]=(f[y][j]+f[x][j])%mod;
				g[y][j]=(g[y][j]+g[x][j])%mod;
			}
			if(t[i]=='1'||t[i]=='?')
			{
				f[y][j-1]=(f[y][j-1]+f[x][j])%mod;
				g[y][j-1]=(g[y][j-1]+g[x][j])%mod;
			}
		}
		
		for(j=0;j<=n+n;j++)
		{
			g[y][j]=(g[y][j]+1ll*f[y][j]*(abs(j-n)))%mod;
		}
	}
	
	printf("%d\n",g[y][n]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
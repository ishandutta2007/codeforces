#include <bits/stdc++.h>
using namespace std;
 
const int mod[3]={1000000007,1000000009,998244353};
int n,m,i,j,f[1000005][3],g[1000005][3];
char mp[1000005];
queue<int> qx,qy;
 
int id(int x,int y)
{
	return (x-1)*m+y;
}
char gtc(int x,int y)
{
	return mp[id(x,y)];
}
 
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf(" ");
		for (j=1;j<=m;j++) scanf("%c",&mp[id(i,j)]);
	}
	
	if (n==1||m==1)
	{
		for (i=2;i<n*m;i++)
		{
			if (mp[i]=='#')
			{
				puts("0");
				return 0;
			}
		}
		puts("1");
		return 0;
	}
	
	f[id(1,1)][0]=f[id(1,1)][1]=f[id(1,1)][2]=1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (i<n&&gtc(i+1,j)=='.')
			{
				(f[id(i+1,j)][0]+=f[id(i,j)][0])%=mod[0];
				(f[id(i+1,j)][1]+=f[id(i,j)][1])%=mod[1];
				(f[id(i+1,j)][2]+=f[id(i,j)][2])%=mod[2];
			}
			if (j<m&&gtc(i,j+1)=='.')
			{
				(f[id(i,j+1)][0]+=f[id(i,j)][0])%=mod[0];
				(f[id(i,j+1)][1]+=f[id(i,j)][1])%=mod[1];
				(f[id(i,j+1)][2]+=f[id(i,j)][2])%=mod[2];
			}
		}
	}
	g[id(n,m)][0]=g[id(n,m)][1]=g[id(n,m)][2]=1;
	for (i=n;i>=1;i--)
	{
		for (j=m;j>=1;j--)
		{
			if (i>1&&gtc(i-1,j)=='.')
			{
				(g[id(i-1,j)][0]+=g[id(i,j)][0])%=mod[0];
				(g[id(i-1,j)][1]+=g[id(i,j)][1])%=mod[1];
				(g[id(i-1,j)][2]+=g[id(i,j)][2])%=mod[2];
			}
			if (j>1&&gtc(i,j-1)=='.')
			{
				(g[id(i,j-1)][0]+=g[id(i,j)][0])%=mod[0];
				(g[id(i,j-1)][1]+=g[id(i,j)][1])%=mod[1];
				(g[id(i,j-1)][2]+=g[id(i,j)][2])%=mod[2];
			}
		}
	}
	
	if (!f[id(n,m)][0]&&!f[id(n,m)][1]&&!f[id(n,m)][2])
	{
		puts("0");
		return 0;
	}
	
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)if(i*j!=1&&i*j!=n*m)
		{
			if (1ll*f[id(i,j)][0]*g[id(i,j)][0]%mod[0]==f[id(n,m)][0])
			{
				if (1ll*f[id(i,j)][1]*g[id(i,j)][1]%mod[1]==f[id(n,m)][1])
				{
					if (1ll*f[id(i,j)][2]*g[id(i,j)][2]%mod[2]==f[id(n,m)][2])
					{
						puts("1");
						return 0;
					}
				}
			}
		}
	}
	
	puts("2");
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,i,a[500005],x,k,j,vis[500005];
struct str{
	long long d,x,f;
}g[1000005];
bool cmp(str a,str b)
{
	return a.d<b.d;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=(n+1)/2;++i)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	if(x>0)
	{
		long long s=0;
		for(i=1;i<=(n+1)/2;++i)
			s+=a[i];
		s+=1ll*x*(n-(n+1)/2);
		if(s>0)
			cout<<n;
		else
			cout<<-1;
	}
	else
	{
		long long mx=1<<30,mn=0;
		long long s=0;
		x=-x;
		for(i=(n+1)/2;i>=1;--i)
		{
			s+=a[i];
			if(s<=0)
				g[++k]=(str){0,i,-1};
			else
				if(x!=0)
					g[++k]=(str){(s+x-1)/x+(n+1)/2-i+1,i,-1};
			g[++k]=(str){n-i+2,i,0};
		}
		sort(g+1,g+1+k,cmp);
		j=1;
		s=0;
		for(i=n/2+1;i<=n;++i)
		{
			while(j<=k&&g[j].d<=i)
			{
				if(g[j].f==-1)
				{
					if(vis[g[j].x]==0)
					{
						vis[g[j].x]=-1;
						--s;
					}
				}
				else
				{
					if(vis[g[j].x]==-1)
						++s;
					vis[g[j].x]=1;
				}
				++j;
			}
			if(s==0)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<-1;
	}
}
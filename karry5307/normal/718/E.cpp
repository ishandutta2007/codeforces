#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res,d;
li r;
ll x[MAXN],dist[MAXN][11],dis[11][11],c[11][511],msk[MAXN];
char ch[MAXN];
vector<ll>v[11];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void upd(ll x,ll c)
{
	x==res?r+=c:1,x>res?res=x,r=c:1;
}
inline void bfs(ll x)
{
	ll top;
	queue<ll>q;
	for(register int i=1;i<=n;i++)
	{
		dist[i][x]=0x3f3f3f3f;
	}
	for(register int i:v[x])
	{
		q.push(i),dist[i][x]=0;
	}
	while(!q.empty())
	{
		top=q.front(),q.pop();
		if(dist[top-1][x]>dist[top][x]+1)
		{
			q.push(top-1),dist[top-1][x]=dist[top][x]+1; 
		}
		if(dist[top+1][x]>dist[top][x]+1)
		{
			q.push(top+1),dist[top+1][x]=dist[top][x]+1; 
		}
	}
}
int main()
{
	n=read(),scanf("%s",ch+1),memset(dis,0x3f,sizeof(dis));
	for(register int i=1;i<=n;i++)
	{
		x[i]=ch[i]&15,v[x[i]].push_back(i); 
	}
	for(register int i=1;i<=8;i++)
	{
		bfs(i),dis[i][i]=0; 
	} 
	for(register int k=1;k<=n;k++)
	{
		for(register int i=1;i<=8;i++)
		{
			for(register int j=1;j<=8;j++)
			{
				dis[i][j]=min(dis[i][j],dist[k][i]+dist[k][j]);
			}
		}
	}
	for(register int k=1;k<=8;k++)
	{
		for(register int i=1;i<=8;i++)
		{
			for(register int j=1;j<=8;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]+1);
			}
		}
	}
	for(register int k=1;k<=8;k++)
	{
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=8;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dis[k][j]+1);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=8;j++)
		{
			msk[i]|=(dist[i][j]-dis[x[i]][j])<<j-1;
		}
	}
	for(register int j=1;j<=n;j++)
	{
		for(register int i=max(1,j-15);i<j;i++)
		{
			d=j-i;
			for(register int k=1;k<=8;k++)
			{
				d=min(d,dist[i][k]+dist[j][k]+1);
			}
			upd(d,1);
		}
	}
	for(register int i=17,j=1;i<=n;i++,j++)
	{
		c[x[j]][msk[j]]++;
		for(register int k=1;k<=8;k++)
		{
			for(register int l=0;l<256;l++)
			{
				if(c[k][l])
				{
					d=2e9;
					for(register int u=1;u<=8;u++)
					{
						d=min(d,dis[k][u]+dist[i][u]+((l>>u-1)&1)+1);
					}
					upd(d,c[k][l]);
				}
			}
		}
	}
	printf("%d %lld\n",res,r);
}
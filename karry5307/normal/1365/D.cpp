#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
ll test,n,m,tot;
ll vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};
char ch[51][51],ch2[51][51];
ll tx[MAXN],ty[MAXN],x[51][51];
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
inline void bfs()
{
	queue<pii>q;
	ll xx,yy,nx,ny;
	x[n][m]=1,q.push((pii){n,m});
	while(!q.empty())
	{
		xx=q.front().first,yy=q.front().second,q.pop();
		for(register int i=0;i<4;i++)
		{
			nx=xx+vx[i],ny=yy+vy[i];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&!x[nx][ny]&&ch2[nx][ny]=='.')
			{
				x[nx][ny]=1,q.push((pii){nx,ny});
			}
		}
	}
}
inline void solve()
{
	n=read(),m=read(),tot=0,memset(x,0,sizeof(x));
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			ch2[i][j]='.';
		}
	}
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
		for(register int j=1;j<=m;j++)
		{
			if(ch[i][j]=='#')
			{
				ch2[i][j]='#';
			}
			if(ch[i][j]=='G')
			{
				tx[++tot]=i,ty[tot]=j;
			}
			if(ch[i][j]=='B')
			{
				for(register int k=0;k<4;k++)
				{
					if(i+vx[k]>0&&i+vx[k]<=n&&j+vy[k]>0&&j+vy[k]<=m)
					{
						ch2[i+vx[k]][j+vy[k]]='#';
					}
				}
			}
		}
	}
	if(!tot)
	{
		return (void)puts("Yes");
	}
	if(ch2[n][m]=='.')
	{
		bfs();
	}
	else
	{
		return (void)puts("No");
	}
	for(register int i=1;i<=tot;i++)
	{
		if(!x[tx[i]][ty[i]])
		{
			return (void)puts("No");
		}
	}
	puts("Yes");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
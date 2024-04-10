#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
ll n,m;
ll vis[MAXN][MAXN],vx[4]={0,1,0,-1},vy[4]={1,0,-1,0};
char ch[MAXN][MAXN];
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
inline void dfs(ll cx,ll cy,ll lstx,ll lsty)
{
	ll nxtx,nxty;
	vis[cx][cy]=1;
	for(register int i=0;i<4;i++)
	{
		nxtx=cx+vx[i],nxty=cy+vy[i];
		if((nxtx!=lstx||nxty!=lsty)&&ch[nxtx][nxty]==ch[cx][cy])
		{
			if(vis[nxtx][nxty])
			{
				puts("Yes"),exit(0);
			}
			dfs(nxtx,nxty,cx,cy);
		}
	}
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
	}	
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			!vis[i][j]?dfs(i,j,-1,-1):(void)1;
		}
	}
	puts("No");
}
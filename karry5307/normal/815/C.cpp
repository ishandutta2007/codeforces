#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=5e3+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll cnt,tot,kk,res;
ll last[MAXN],x[MAXN],y[MAXN],dep[MAXN],size[MAXN],dp[MAXN][MAXN][2];
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
template <class T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void DP(ll node,ll fa)
{
	size[node]=1,dp[node][0][0]=0,dp[node][1][0]=x[node];
	dp[node][1][1]=x[node]-y[node];
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			DP(ed[i].to,node);
			for(register int j=size[node];j>=0;j--)
			{
				for(register int k=0;k<=size[ed[i].to];k++)
				{
					dp[node][j+k][0]=Min(dp[node][j+k][0],dp[node][j][0]+dp[ed[i].to][k][0]);
					dp[node][j+k][1]=Min(dp[node][j+k][1],dp[node][j][1]+dp[ed[i].to][k][1]);
					dp[node][j+k][1]=Min(dp[node][j+k][1],dp[node][j][1]+dp[ed[i].to][k][0]);
				}
			}
			size[node]+=size[ed[i].to];
		}
	}
}
int main()
{
	cnt=read(),kk=read(),x[1]=read(),y[1]=read();
	for(register int i=2;i<=cnt;i++)
	{
		x[i]=read(),y[i]=read(),dep[i]=read();
		addEdge(i,dep[i]),addEdge(dep[i],i); 
	}
	memset(dp,0x3f,sizeof(dp)),DP(1,0);
	for(register int i=cnt;i>=1;i--)
	{
		if(dp[1][i][1]<=kk||dp[1][i][0]<=kk)
		{
			res=i;
			break;
		}
	}
	printf("%lld\n",res);
}
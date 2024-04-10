#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,x,y;
ll col[MAXN],lstx[MAXN],lsty[MAXN];
vector<ll>vg[MAXN];
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
inline void addEdge(ll u,ll v)
{
	vg[u].push_back(v),vg[v].push_back(u);
}
inline void dfs(ll x,ll c)
{
	col[x]=c;
	for(register int i:vg[x])
	{
		col[i]==-1?dfs(i,c^1):(void)1;
	}
}
int main()
{
	n=read(),memset(col,-1,sizeof(col));
	for(register int i=1;i<=n;i++)
	{
		x=read(),y=read();
		lstx[x]?addEdge(i,lstx[x]),lstx[x]=0:lstx[x]=i;
		lsty[y]?addEdge(i,lsty[y]),lsty[y]=0:lsty[y]=i;
	}
	for(register int i=1;i<=n;i++)
	{
		col[i]==-1?dfs(i,0):(void)1;
	}
	for(register int i=1;i<=n;i++)
	{
		putchar("rb"[col[i]]);
	}
}
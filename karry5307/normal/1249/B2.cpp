#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e6+51;
ll test,cnt,tot;
ll vis[MAXN],perm[MAXN],bel[MAXN],size[MAXN];
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
inline ll dfs(ll cur,ll cnt,ll tot)
{
	if(vis[cur])
	{
		return cnt;
	}
	vis[cur]=1,size[tot]++,bel[cur]=tot;
	return dfs(perm[cur],cnt+1,tot);
}
inline void solve()
{
	for(register int i=1;i<=cnt;i++)
	{
		if(!vis[i])
		{
			dfs(i,0,++tot);
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",size[bel[i]]);
	}
	puts("");
}
int main()
{
	test=read();
	for(register int t=0;t<test;t++)
	{
		cnt=read();
		for(register int i=1;i<=cnt;i++)
		{
			perm[i]=read();
		}
		solve();
		tot=0,
		memset(vis,0,sizeof(vis)),memset(bel,0,sizeof(bel));
		memset(size,0,sizeof(size));
	}
}
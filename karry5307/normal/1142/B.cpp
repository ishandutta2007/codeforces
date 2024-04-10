#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll cnt,ccnt,qcnt,tot,x,y;
ll perm[MAXN],num[MAXN],prv[MAXN],prv2[MAXN],lst[MAXN],lnk[MAXN];
ll last[MAXN],prv3[MAXN],lk[MAXN],res[MAXN],depth[MAXN],rd[MAXN];
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
inline void link(ll x,ll y)
{
	prv3[++tot]=last[x];
	lk[tot]=y;
	last[x]=tot;
}
inline void dfs(ll node)
{
	rd[depth[node]]=node;
	res[node]=((depth[node]>=cnt)?rd[depth[node]-cnt+1]:ccnt+1);
	for(register int i=last[node];i;i=prv3[i])
	{
		depth[lk[i]]=depth[node]+1,dfs(lk[i]);
	}
}
int main()
{
	cnt=read(),ccnt=read(),qcnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		prv[(perm[i]=read())]=perm[i-1];
	}
	prv[perm[1]]=perm[cnt];
	for(register int i=1;i<=ccnt;i++)
	{
		prv2[i]=lst[(num[i]=read())],lst[num[i]]=i;
		for(register int j=lst[prv[num[i]]];j&&!lnk[j];j=prv2[j])
		{
			lnk[j]=i;
		}
	}
	for(register int i=1;i<=ccnt;i++)
	{
		link(lnk[i]?lnk[i]:ccnt+1,i);
	}
	dfs(ccnt+1);
	for(register int i=ccnt-1;i;i--)
	{
		res[i]=min(res[i+1],res[i]);
	}
	for(register int i=0;i<qcnt;i++)
	{
		x=read(),y=read();
		putchar((res[x]<=y)+'0');
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,cnt,pos;
ll vis[MAXN],perm[MAXN],rp[MAXN];
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
inline void solve()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		perm[i]=read(),rp[perm[i]]=i;
	}
	for(register int i=1;i<=cnt;i++)
	{
		pos=rp[i];
		while(pos!=1&&!vis[pos-1]&&perm[pos]<perm[pos-1])
		{
			swap(perm[pos],perm[pos-1]);
			rp[perm[pos]]=pos,rp[perm[pos-1]]=pos-1,pos--;
			vis[pos]=1;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",perm[i]);
	}
	puts(""),memset(vis,0,sizeof(vis));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
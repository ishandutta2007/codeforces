#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
unordered_map<ll,ll>rp;
ll n,p,q,mx;
ll ffa[MAXN],v[MAXN];
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
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline void merge(ll x,ll y)
{
	ll ffx=find(x),ffy=find(y);
	if(ffx!=ffy)
	{
		ffa[ffy]=ffx;
	}
}
int main()
{
	n=read(),p=read(),q=read(),ffa[n+1]=n+1,ffa[n+2]=n+2;
	for(register int i=1;i<=n;i++)
	{
		rp[v[i]=read()]=i,mx=max(mx,v[i]),ffa[i]=i;
	}
	if(mx>=max(p,q))
	{
		return puts("NO"),0;
	}
	for(register int i=1;i<=n;i++)
	{
		merge(i,rp[p-v[i]]>0?rp[p-v[i]]:n+1);
		merge(i,rp[q-v[i]]>0?rp[q-v[i]]:n+2);
	}
	if(find(n+2)!=find(n+1))
	{
		puts("YES");
		for(register int i=1;i<=n;i++)
		{
			printf("%d ",find(i)!=find(n+2)?1:0);
		}
		return 0;
	}
	puts("NO");
}
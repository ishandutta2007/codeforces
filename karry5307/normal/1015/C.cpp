#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,m,sum,sum2;
ll u[MAXN],v[MAXN],id[MAXN];
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
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		sum+=(u[i]=read()),sum2+=(v[i]=read()),id[i]=i;
	}
	if(sum<=m)
	{
		return puts("0"),0;
	}
	if(sum2>m)
	{
		return puts("-1"),0;
	}
	sort(id+1,id+n+1,[&](ll x,ll y){return u[x]-v[x]>u[y]-v[y];});
	for(register int i=1;i<=n;i++)
	{
		if((sum+=v[id[i]]-u[id[i]])<=m)
		{
			return printf("%d\n",i),0;
		}
	}
}
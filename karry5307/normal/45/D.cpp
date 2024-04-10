#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,cur;
ll l[MAXN],r[MAXN],vis[MAXN],res[MAXN];
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
inline ll check(ll x,ll y)
{
	return l[x]==l[y]?r[x]<r[y]:l[x]<l[y];
}
int main()
{
	n=read(),l[0]=r[0]=0x3f3f3f3f;
	for(register int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read();
	}	
	for(register int i=1;i<=n;i++)
	{
		cur=0;
		for(register int j=1;j<=n;j++)
		{
			!vis[j]&&check(j,cur)?cur=j:1;
		}
		res[cur]=l[cur],vis[cur]=1;
		for(register int j=1;j<=n;j++)
		{
			l[j]=max(l[j],res[cur]+1);
		}
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
	}
}
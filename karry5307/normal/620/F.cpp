#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,mx;
ll x[MAXN],l[MAXN],r[MAXN],res[MAXN],f[MAXN],prefix[MAXN*5];
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
		mx=max(mx,x[i]=read());
	}
	for(register int i=1;i<=mx;i++)
	{
		prefix[i]=prefix[i-1]^i;
	}
	for(register int i=1;i<=m;i++)
	{
		l[i]=read(),r[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		f[i]=x[i];
		for(register int j=i+1;j<=n;j++)
		{
			f[j]=max(f[j-1],prefix[max(x[i],x[j])]^prefix[min(x[i],x[j])-1]);
		}
		for(register int j=1;j<=m;j++)
		{
			if(i>=l[j]&&i<=r[j])
			{
				res[j]=max(res[j],f[r[j]]);
			}
		}
	}
	for(register int i=1;i<=m;i++)
	{
		printf("%d\n",res[i]);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,p,pr;
ll x[MAXN];
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
	n=read(),pr=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	sort(x+1,x+n+1,greater<ll>());
	for(register int i=2;i<=n;i++)
	{
		p=i,pr=__gcd(pr,x[i-1]);
		for(register int j=i+1;j<=n;j++)
		{
			if(__gcd(pr,x[j])>__gcd(pr,x[p]))
			{
				p=j;
			}
			else
			{
				if(__gcd(pr,x[j])==__gcd(pr,x[p])&&x[j]>x[p])
				{
					p=j;
				}
			}
		}
		swap(x[p],x[i]);
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",x[i]);
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=1;i<=test;i++)
	{
		solve();
	}
}
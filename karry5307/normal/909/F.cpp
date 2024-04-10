#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,x;
ll res[MAXN];
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
inline void calc1(ll n)
{
	if(n<=0)
	{
		return;
	}
	ll x=31-__builtin_clz(n);
	reverse(res+(1<<x+1)-n-1,res+n+1);
	calc1((1<<x+1)-n-2);
}
inline void solve1()
{
	if(n&1)
	{
		return (void)puts("NO");
	}
	puts("YES");
	for(register int i=1;i<=n;i++)
	{
		res[i]=i;
	}
	calc1(n);
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
	}
	puts("");
}
inline void solve2()
{
	if(n==3||n==5||n==(n&-n))
	{
		return (void)puts("NO");
	}
	puts("YES");
	for(register int i=1;i<=n;i++)
	{
		res[i]=i;
	}
	if(n&1)
	{
		printf("3 6 1 5 7 2 4 ");
		for(register int i=8;i<=n;i+=2)
		{
			swap(res[i],res[i^1]);
		}
		for(register int i=8;i<=n;i++)
		{
			printf("%d ",res[i]);
		}
	}
	else
	{
		for(register int i=2;i<=n-3;i+=2)
		{
			swap(res[i],res[i+1]);
		}
		swap(res[1],res[n-1]),swap(res[n],res[n-2]);
		for(register int i=1;i<=n;i++)
		{
			printf("%d ",res[i]);
		}
	}
	puts("");
}
int main()
{
	n=read(),solve1(),solve2();
}
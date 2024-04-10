#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,m,pos,r;
double pr,res;
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
	n=read(),m=read(),res=1,r=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=n;i>=1;i--)
	{
		if(x[i]!=i)
		{
			r=i;
			break;
		}
	}
	for(register int i=1;i<=m;i++)
	{
		pos=read(),scanf("%lf",&pr),pos>=r?res*=(1-pr):1.0;
	}
	printf("%.6lf\n",r?1-res:1);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,kk,res; 
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
	n=read(),kk=read(),res=-0x3f3f3f3f;
	for(register int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(i<=kk)
			{
				res=max(res,i);
			}
			if(n/i<=kk)
			{
				res=max(res,n/i);
			}
		}
	}
	printf("%d\n",n/res);
}
int main()
{
	test=read();
	for(register int i=1;i<=test;i++)
	{
		solve();
	}
}
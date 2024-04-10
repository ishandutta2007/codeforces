#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,d,res;
ll x[MAXN],r[3];
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
	n=read(),r[0]=r[1]=r[2]=0,res=0;
	for(register int i=1;i<=n;i++)
	{
		r[(x[i]=read())%3]++;
	}
	r[0]-=n/3,r[1]-=n/3,r[2]-=n/3;
	for(register int i=0;i<=2;i++)
	{
		for(register int j=0;j<=2;j++)
		{
			if(r[i]>0&&r[j]<0)
			{
				d=min(r[i],-r[j]),r[i]-=d,r[j]+=d;
				res+=d*((j-i+3)%3);
			}
		}
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
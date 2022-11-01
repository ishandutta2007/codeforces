#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,kk,r,res;
ll x[MAXN],f[MAXN],mx[MAXN];
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
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		read();
	}
	sort(x+1,x+n+1),r=1,res=0,f[n+1]=mx[n+1]=0;
	for(register int i=1;i<=n;i++)
	{
		while(r<n&&x[r+1]-x[i]<=kk)
		{
			r++;
		}
		f[i]=r-i+1;
	}
	for(register int i=n;i;i--)
	{
		mx[i]=max(mx[i+1],f[i]);
	}
	for(register int i=1;i<=n;i++)
	{
		res=max(res,f[i]+mx[i+f[i]]);
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
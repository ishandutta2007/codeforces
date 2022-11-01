#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define lwb lower_bound
#define upb upper_bound
using namespace std;
typedef int ll;
const ll MAXN=5051;
ll test,n,m,k,res,r,lx,rx,x;
ll num[MAXN];
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
	n=read(),m=read(),k=read(),res=0,r=max(0,m-k-1);
	for(register int i=1;i<=n;i++)
	{
		num[i]=read();
	}
	if(!r)
	{
		for(register int i=1;i<=n;i++)
		{
			if(i<=m||i>n-m)
			{
				res=max(res,num[i]);
			}
		}
		printf("%d\n",res);
		return;
	}
	for(register int i=0;i<=min(m-1,k);i++)
	{
		lx=i+1,rx=n-k+i,x=0x3f3f3f3f;
		for(register int j=0;j<=r;j++)
		{
			x=min(x,max(num[lx+j],num[rx-r+j]));
		}
		res=max(res,x);
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
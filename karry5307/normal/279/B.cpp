#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,l,r,sm,res;
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
int main()
{
	n=read(),m=read(),l=n+1,r=n,sm=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	while(l>1)
	{
		sm+=x[--l];
		while(sm>m)
		{
			sm-=x[r--];
		}
		res=max(res,r-l+1);
	}
	printf("%d\n",res);
	
}
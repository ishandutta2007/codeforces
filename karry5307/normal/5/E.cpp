#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e6+51;
ll cnt,kk,maxn,res;
ll x[MAXN],y[MAXN],z[MAXN],l[MAXN],r[MAXN];
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
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		x[i]=read();
		if(x[i]>maxn)
		{
			maxn=x[i],kk=i;
		}
	}
	kk--;
	for(register int i=1;i<=cnt;i++)
	{
		y[i]=x[(kk+i)%cnt];
	}
	l[1]=1;
	for(register int i=2;i<=cnt;i++)
	{
		l[i]=i-1;
		while(l[i]>1&&y[l[i]]<=y[i])
		{
			l[i]=l[l[i]];
		}
	}
	for(register int i=cnt;i;i--)
	{
		r[i]=i+1;
		while(r[i]<=cnt&&y[r[i]]<y[i])
		{
			r[i]=r[r[i]];
		}
		if(r[i]<=cnt&&y[r[i]]==y[i])
		{
			z[i]=z[r[i]]+1,r[i]=r[r[i]];
		}
	}
	for(register int i=2;i<=cnt;i++)
	{
		res+=z[i]+2;
		if(l[i]==1&&r[i]==cnt+1)
		{
			res--;
		}
	}
	printf("%lld\n",res);
}
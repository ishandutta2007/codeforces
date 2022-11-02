#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef double db;
const ll MAXN=2e5+51;
const db eps=1e-10;
struct Tuple{
    ll x,t;
    db rx,l,r;
    inline bool operator <(const Tuple &rhs)const
    {
		return rx>rhs.rx;
    }
    inline bool operator >(const Tuple &rhs)const
    {
		return x<rhs.x;
    }
};
ll n,ptr;
li sumt,s;
db res=1,l,r;
Tuple p[MAXN];
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
    n=read();
    for(register int i=1;i<=n;i++)
    {
		p[i].x=read();
    }
    for(register int i=1;i<=n;i++)
    {
		sumt+=(p[i].t=read()),p[i].rx=1.0*p[i].x/p[i].t;
    }
    sort(p+1,p+n+1);
    for(register int i=1,j=0;i<=n;i=j+1)
    {
		while(j+1<=n&&fabs(p[i].rx-p[j+1].rx)<eps)
		{
		    j++;
		}
		for(register int k=i;k<=j;k++)
		{
		    p[k].l=1.0*p[k].x*(s+p[k].t)/sumt;
		}
		for(register int k=i;k<=j;k++)
		{
		    s+=p[k].t;
		}
		for(register int k=i;k<=j;k++)
		{
		    p[k].r=1.0*p[k].x*s/sumt;
		}
    }
    sort(p+1,p+n+1,greater<Tuple>());   
    for(register int i=1;i<n;i++)
    {
    	if(p[i].x<p[i+1].x)
    	{
    		l=1e8,r=0,ptr=i;
    		while(ptr&&p[ptr].x==p[i].x)
    		{
    			l=min(l,p[ptr--].l);
			}
			ptr=i+1;
    		while(ptr<=n&&p[ptr].x==p[i+1].x)
			{
				r=max(r,p[ptr++].r);	
			} 
			if(l+eps<r)
			{
				res=min(res,(p[i].x-p[i+1].x)/(l-r));
			}
		}
	}
	printf("%.7lf\n",res);
}
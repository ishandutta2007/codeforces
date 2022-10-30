#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=4e5+51;
struct Trap{
	ll l,r,d;
	inline bool operator <(const Trap &rhs)const
	{
		return this->l<rhs.l;	
	} 
}; 
Trap p[MAXN];
ll cnt,x,ccnt,t,l,r,mid,res;
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
inline bool check(ll mid)
{
	ll v=num[cnt-mid+1],r=0,lp=0,rp=0;
	for(register int i=0;i<ccnt;i++)
	{
		if(p[i].d>v)
		{
			if(p[i].l<=rp)
			{
				rp=max(rp,p[i].r);
			}
			else
			{
				r+=(rp-lp)*3+p[i].l-rp-1,lp=p[i].l-1,rp=p[i].r;
			}
		}
	}
	r+=(rp-lp)*3+(x+1-rp);
	return r<=t;
}
int main()
{
	cnt=read(),x=read(),ccnt=read(),t=read();
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
	}
	for(register int i=0;i<ccnt;i++)
	{
		p[i].l=read(),p[i].r=read(),p[i].d=read();
	}
	sort(num+1,num+cnt+1),sort(p,p+ccnt),l=1,r=cnt;
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?l=mid+1,res=mid:r=mid-1;
	}
	printf("%d\n",res); 
}
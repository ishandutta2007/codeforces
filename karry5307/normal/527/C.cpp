#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
struct Interval{
	ll l,r;
	inline ll get()const
	{
		return r-l+1;
	}
	inline bool operator <(const Interval &rhs)const
	{
		return r-l==rhs.r-rhs.l?l<rhs.l:r-l>rhs.r-rhs.l;
	}
};
set<Interval>r,c;
set<ll>rx,cx;
set<ll>::iterator it;
ll n,m,kk,x,lp,rp;
char ch;
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
	n=read(),m=read(),kk=read();
	r.insert((Interval){1,n}),c.insert((Interval){1,m});
	rx.insert(1),rx.insert(n),cx.insert(1),cx.insert(m);
	for(register int i=0;i<kk;i++)
	{
		cin>>ch>>x;
		if(ch=='H')
		{
			it=cx.upper_bound(x),rp=*it--,lp=*it,c.erase((Interval){lp,rp});
			c.insert((Interval){lp,x}),c.insert((Interval){x+1,rp});
			cx.insert(x),cx.insert(x+1);
		}
		else
		{
			it=rx.upper_bound(x),rp=*it--,lp=*it,r.erase((Interval){lp,rp});
			r.insert((Interval){lp,x}),r.insert((Interval){x+1,rp});
			rx.insert(x),rx.insert(x+1);
		}
		printf("%lld\n",(li)(*c.begin()).get()*(*r.begin()).get());
	}
}
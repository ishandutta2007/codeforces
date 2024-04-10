#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Node{
	ll h,d;
	inline bool operator <(const Node &rhs)const
	{
		return h<rhs.h;
	}
};
Node c[MAXN];
ll n,sm,res,l,r,cur,p,tt;
priority_queue<ll>q1;
priority_queue<ll,vector<ll>,greater<ll> >q2;
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
		c[i].h=read();
	}
	for(register int i=1;i<=n;i++)
	{
		sm+=(c[i].d=read());
	}
	sort(c+1,c+n+1),l=r=1;
	while(l<=n)
	{
		cur=c[l].h,p=0;
		while(c[r].h==cur)
		{
			p+=c[r++].d;	
		}
		while(q2.size()<r-l-1&&!q1.empty())
		{
			tt+=q1.top(),q2.push(q1.top()),q1.pop();
		}
		while(q2.size()>r-l-1&&!q2.empty())
		{
			tt-=q2.top(),q1.push(q2.top()),q2.pop();
		}
		res=max(res,tt+p);
		while(l<r)
		{
			if(q1.empty()||c[l].d>q1.top())
			{
				q2.push(c[l].d),tt+=c[l].d;
			}
			else
			{
				q1.push(c[l].d);
			}
			l++;
		}
	}
	printf("%lld\n",sm-res);
}
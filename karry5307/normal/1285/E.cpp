#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=4e5+51;
struct Segment{
	ll l,r;
	inline bool operator <(const Segment &rhs) const
	{
		return this->l<rhs.l;
	}
};
Segment s[MAXN];
ll test,cnt,tot,res,p0,p1,in;
ll dis[MAXN],mx[2][MAXN],p[2][MAXN];
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
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		s[i].l=read(),s[i].r=read();
		dis[++tot]=s[i].l,dis[++tot]=s[i].r;
	}
	sort(dis+1,dis+tot+1),tot=unique(dis+1,dis+tot+1)-dis-1;
	for(register int i=1;i<=cnt;i++)
	{
		s[i].l=lower_bound(dis+1,dis+tot+1,s[i].l)-dis;
		s[i].r=lower_bound(dis+1,dis+tot+1,s[i].r)-dis;
	}
	sort(s+1,s+cnt+1),res=0;
	for(register int i=0;i<=cnt;i++)
	{
		mx[0][i]=mx[1][i]=-1998244353;
	}
	for(register int i=1;i<=cnt;i++)
	{
		mx[0][i]=mx[0][i-1],mx[1][i]=mx[1][i-1];
		if(s[i].r>mx[0][i])
		{
			mx[1][i]=mx[0][i],mx[0][i]=s[i].r;
		}
		else
		{
			mx[1][i]=max(mx[1][i],s[i].r);
		}
		p[0][i]=p[0][i-1]+(s[i].l>mx[0][i-1]),p[1][i]=p[1][i-1]+(s[i].l>mx[1][i-1]);
	}
	for(register int i=1;i<=cnt;i++)
	{
		p0=lower_bound(mx[0]+i,mx[0]+cnt+1,s[i].r)-mx[0];
		p1=lower_bound(mx[0]+i,mx[0]+cnt+1,s[i].r+1)-mx[0];
		if(mx[0][p0]!=s[i].r)
		{
			res=max(res,p[0][cnt]);
		}
		else
		{
			p1--;
			assert(mx[0][p1]==s[i].r);
			in=(bool)(i>=p0+1&&i<=p1+1&&s[i].l>mx[1][i-1]||(i<p0+1||i>p1+1)&&s[i].l>mx[0][i-1]);
			res=max(res,p[0][p0]+p[1][min(cnt,p1+1)]-p[1][p0]+p[0][cnt]-p[0][min(cnt,p1+1)]-in);
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
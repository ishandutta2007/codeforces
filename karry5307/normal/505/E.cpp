#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Node{
	ll d,id;
	inline bool operator <(const Node &rhs)const
	{
		return d>rhs.d;
	}
};
priority_queue<Node>q;
ll n,m,kk,p,l,r,mid,res;
ll c[MAXN],x[MAXN],h[MAXN];
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
inline ll check(ll mid)
{
	ll d,id;
	while(!q.empty())
	{
		q.pop();
	}
	memset(c,0,sizeof(c));
	for(register int i=1;i<=n;i++)
	{
		mid-x[i]*m<h[i]?q.push((Node){mid/x[i],i}):(void)1;
	}
	for(register int i=1;i<=m&&!q.empty();i++)
	{
		for(register int j=1;j<=kk&&!q.empty();j++)
		{
			d=q.top().d,id=q.top().id,q.pop();
			if(d<i)
			{
				return 0;
			}
			if(mid+(++c[id])*p-x[id]*m<h[id])
			{
				q.push((Node){(mid+c[id]*p)/x[id],id});
			}
		}
	}
	return q.empty();
}
int main()
{
	n=read(),m=read(),kk=read(),p=read();
	for(register int i=1;i<=n;i++)
	{
		h[i]=read(),x[i]=read(),r=max(r,h[i]+x[i]*m);
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?res=mid,r=mid-1:l=mid+1;
	}
	printf("%lld\n",res);
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef set<pair<ll,ll> >::iterator sit;
const ll MAXN=2e5+51;
struct Node{
	ll l,r,id,type;
	inline bool operator <(const Node &rhs)const
	{
		return this->r<rhs.r;
	}
};
Node x[MAXN],y[MAXN];
set<pair<ll,ll> >st;
ll cnt,ccnt,cur=1;
ll res[MAXN];
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
	for(register int i=1;i<=cnt;i++)
	{
		x[i].l=read(),x[i].r=read(),x[i].id=i,x[i].type=-1;
	}
	ccnt=read();
	for(register int i=1;i<=ccnt;i++)
	{
		y[i].l=read(),y[i].r=read(),y[i].type=read(),y[i].id=i;
	}
	sort(x+1,x+cnt+1),sort(y+1,y+ccnt+1);
	for(register int i=1;i<=ccnt;i++)
	{
		while(y[i].r>=x[cur].r&&cur<=cnt)
		{
			st.insert(make_pair(x[cur].l,cur)),cur++;
		}
		while(y[i].type--)
		{
			sit it=st.lower_bound(make_pair(y[i].l,0));
			if(it==st.end())
			{
				break;
			}
			res[x[it->second].id]=y[i].id,st.erase(it);
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(!res[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",res[i]);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll>::iterator vi;
typedef long long int li;
const ll MAXN=3e5+51,inf=0x3f3f3f3f;
struct SegmentTree{
	ll l,r;
	vector<ll>num;
};
struct Query{
	ll l,r,id;
	inline bool operator <(const Query &rhs)const
	{
		return this->r<rhs.r;
	}
};
SegmentTree tree[MAXN<<2];
Query qry[MAXN];
ll cnt,qcnt,ptr;
ll num[MAXN],ress[MAXN<<2],res[MAXN<<2];
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
template <class T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
inline void update(ll node)
{
	ll ls=node<<1,rs=ls|1;
	ress[node]=Min(ress[node],Min(ress[ls],ress[rs]));
	ptr=Min(ptr,ress[node]);
}
inline void create(ll l,ll r,ll node)
{
	tree[node].l=l,tree[node].r=r;
	for(register int i=l;i<=r;i++)
	{
		tree[node].num.push_back(num[i]);
	}
	ress[node]=inf;
	sort(tree[node].num.begin(),tree[node].num.end());
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1;
	create(l,mid,node<<1);
	create(mid+1,r,(node<<1)|1);
}
inline void change(ll pos,ll val,ll node)
{
	if(tree[node].r<=pos)
	{
		vi it=upper_bound(tree[node].num.begin(),tree[node].num.end(),val);
		if(it!=tree[node].num.end())
		{
			ress[node]=Min(ress[node],*it-val);
		}
		if(it!=tree[node].num.begin())
		{
			ress[node]=Min(ress[node],val-*(it-1));
		}
		if(ptr<=ress[node])
		{
			return;
		}
		if(tree[node].l==tree[node].r)
		{
			ptr=Min(ptr,ress[node]);
			return;
		}
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
	if(pos>mid)
	{
		change(pos,val,(node<<1)|1);
	}
	change(pos,val,node<<1),update(node);
}
inline ll query(ll l,ll r,ll node)
{
	if(l<=tree[node].l&&r>=tree[node].r)
	{
		return ress[node];
	}
	ll mid=(tree[node].l+tree[node].r)>>1,res=inf;
	if(l<=mid)
	{
		res=Min(res,query(l,r,node<<1));
	}
	if(r>mid)
	{
		res=Min(res,query(l,r,(node<<1|1)));
	}
	return res;
}
int main()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
	}
	create(1,cnt,1),qcnt=read();
	for(register int i=1;i<=qcnt;i++)
	{
		qry[i].l=read(),qry[i].r=read(),qry[i].id=i;
	}
	sort(qry+1,qry+qcnt+1);
	for(register int p=1,i=2;i<=cnt;i++)
	{
		ptr=inf,change(i-1,num[i],1);
		for(;p<=qcnt&&qry[p].r<=i;p++)
		{
			res[qry[p].id]=query(qry[p].l,i,1);
		}
	}
	for(register int i=1;i<=qcnt;i++)
	{
		printf("%d\n",res[i]);
	}
}
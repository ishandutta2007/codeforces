#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll cnt,qcnt,seed,maxv,sa,op,l,r,x,y;
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
inline ll qpow(ll base,ll exponent,ll mod)
{
	ll res=1;
	base%=mod;
	while(exponent)
	{
		if(exponent&1)
		{
			res=res*base%mod;
		}
		base=base*base%mod,exponent>>=1;
	}
	return res;
}
inline ll rd()
{
	sa=seed,seed=(seed*7+13)%1000000007;
	return sa;
}
inline ll rd(ll r)
{
	return (rd()%r)+1;
}
namespace ChthollyTree{
	struct Node{
		ll l,r;
		mutable ll val;
		Node(ll l,ll r=-1,ll val=0)
		{
			this->l=l,this->r=r,this->val=val;
		}
		inline bool operator <(const Node &rhs)const
		{
			return this->l<rhs.l;
		}
	};
	typedef set<Node>::iterator sit;
	struct ChthollyTree{
		set<Node>st;
		inline sit split(ll pos)
		{
			sit it=st.lower_bound(Node(pos));
			if(it!=st.end()&&it->l==pos)
			{
				return it;
			}
			--it;
			ll l=it->l,r=it->r,val=it->val;
			st.erase(it),st.insert(Node(l,pos-1,val));
			return st.insert(Node(pos,r,val)).first;
		}
		inline void assign(ll l,ll r,ll val=0)
		{
			sit sl=split(l),sr=split(r+1);
			st.erase(sl,sr),st.insert(Node(l,r,val));
		}
		inline void add(ll l,ll r,ll val=1)
		{
			sit sl=split(l),sr=split(r+1);
			for(;sl!=sr;++sl)
			{
				sl->val+=val;
			}
		}
		inline ll findVal(ll l,ll r,ll rk)
		{
			vector<pair<ll,ll> >v;
			sit sl=split(l),sr=split(r+1);
			v.clear();
			for(;sl!=sr;++sl)
			{
				v.push_back(make_pair(sl->val,sl->r-sl->l+1));
			}
			sort(v.begin(),v.end());
			for(vector<pair<ll,ll> >::iterator it=v.begin();it!=v.end();++it)
			{
				rk-=it->second;
				if(rk<=0)
				{
					return it->first;
				}
			}
			return -1;
		}
		inline ll queryPow(ll l,ll r,ll exponent,ll mod)
		{
			sit sl=split(l),sr=split(r+1);
			ll res=0;
			for(;sl!=sr;++sl)
			{
				res=(res+(sl->r-sl->l+1)%mod*qpow(sl->val,exponent,mod)%mod)%mod;
			}
			return res;
		}
	};
}
using ChthollyTree::Node;
ChthollyTree::ChthollyTree ct;
int main()
{
	cnt=read(),qcnt=read(),seed=read(),maxv=read();
	for(register int i=1;i<=cnt;i++)
	{
		ct.st.insert(Node(i,i,rd(maxv)));
	}
	ct.st.insert(Node(cnt+1,cnt+1,0));
	for(register int i=1;i<=qcnt;i++)
	{
		op=rd(4),l=rd(cnt),r=rd(cnt);
		if(l>r)
		{
			swap(l,r);
		}
		x=rd(op==3?r-l+1:maxv);
		if(op==1)
		{
			ct.add(l,r,x);
		}
		if(op==2)
		{
			ct.assign(l,r,x);
		}
		if(op==3)
		{
			printf("%lld\n",ct.findVal(l,r,x));
		}
		if(op==4)
		{
			y=rd(maxv);
			printf("%lld\n",ct.queryPow(l,r,x,y));
		}
	}
}
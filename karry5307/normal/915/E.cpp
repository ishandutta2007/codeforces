#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll cnt,qcnt,op,l,r,res;
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
			sit sr=split(r+1),sl=split(l),slx=sl;
			for(;slx!=sr;slx++)
			{
				res-=(slx->r-slx->l+1)*slx->val;
			}
			st.erase(sl,sr),st.insert(Node(l,r,val));
			res+=(r-l+1)*val;
		}
	};
}
using ChthollyTree::Node;
ChthollyTree::ChthollyTree ct;
int main()
{
	res=cnt=read(),qcnt=read(),ct.st.insert((Node){1,cnt,1});
	for(register int i=0;i<qcnt;i++)
	{
		l=read(),r=read(),op=read();
		ct.assign(l,r,op-1);
		printf("%d\n",res);
	}
}
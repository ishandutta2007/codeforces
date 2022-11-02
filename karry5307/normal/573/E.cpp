#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51,inf=0x7fffffffffffffff;
ll cnt,x,l,r,res,mid;
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
inline T Max(T x,T y)
{
	return x>y?x:y;
}
namespace Splay{
	struct Node{
		ll fa,sz;
		ll p,q,val;
		ll ch[2];
	};
	struct Splay{
		ll tot,rt;
		Node nd[MAXN];
		ll st[MAXN];
		inline ll id(ll x)
		{
			return nd[nd[x].fa].ch[1]==x;
		}
		inline void update(ll x)
		{
			nd[x].sz=nd[nd[x].ch[0]].sz+nd[nd[x].ch[1]].sz+1;
		}
		inline void create()
		{
			nd[++tot].fa=rt,nd[nd[rt].ch[1]].fa=tot;
			nd[tot].ch[1]=nd[rt].ch[1],nd[rt].ch[1]=tot;
			nd[tot].val=nd[rt].val;
		}
		inline void change(ll x,ll p,ll q)
		{
			nd[x].val+=p*(nd[nd[x].ch[0]].sz+1)+q;
			nd[x].p+=p,nd[x].q+=q;
		}
		inline void spread(ll x)
		{
			if(nd[x].p||nd[x].q)
			{
				ll p=nd[x].p,q=nd[x].q;
				if(nd[x].ch[0])
				{
					change(nd[x].ch[0],p,q);
				}
				if(nd[x].ch[1])
				{
					change(nd[x].ch[1],p,q+p*(nd[nd[x].ch[0]].sz+1));
				}
				nd[x].p=nd[x].q=0;
			}
		}
		inline void rotate(ll x)
		{
			ll fa=nd[x].fa,gfa=nd[fa].fa,dir=id(x);
			if(gfa)
			{
				nd[gfa].ch[id(fa)]=x;
			}
			nd[x].fa=gfa,nd[fa].fa=x,nd[nd[x].ch[!dir]].fa=fa;
			nd[fa].ch[dir]=nd[x].ch[!dir],nd[x].ch[!dir]=fa;
			update(fa);
		}
		inline void splay(ll x)
		{
			ll top=0,fa=x;
			st[++top]=fa;
			while(nd[fa].fa)
			{
				st[++top]=fa=nd[fa].fa;
			}
			while(top)
			{
				spread(st[top--]);
			}
			while(nd[x].fa)
			{
				if(nd[nd[x].fa].fa)
				{
					rotate(id(x)^id(nd[x].fa)?x:nd[x].fa);
				}	
				rotate(x);
			}
			update(rt=x);
		}
		inline ll findVal(ll rk)
		{
			ll x=rt,sz;
			while(1)
			{
				if(nd[nd[x].ch[0]].sz+1==rk)
				{
					splay(x);
					return nd[x].val;
				}
				if(nd[nd[x].ch[0]].sz>=rk)
				{
					x=nd[x].ch[0];
				}
				else
				{
					rk-=nd[nd[x].ch[0]].sz+1,x=nd[x].ch[1];
				}
			}
		}
		inline ll chkmax(ll x)
		{
			if(!x)
			{
				return -inf;
			}
			spread(x);
			ll ls=nd[x].ch[0],rs=nd[x].ch[1];
			return Max(nd[x].val,Max(chkmax(ls),chkmax(rs)));
		}
	};
}
Splay::Splay splay; 
inline ll get(ll x)
{
	return splay.findVal(x);
}
int main()
{
	cnt=read(),splay.nd[1].sz=splay.rt=splay.tot=1;
	for(register int i=1;i<=cnt;i++)
	{
		x=read(),l=0,r=i-2,res=i-1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			(get(mid+1)+(ll)(mid+1)*x>get(mid+2))?r=mid-1,res=mid:l=mid+1;
		}
		get(res+1),splay.create(),splay.change(splay.tot,x,(ll)x*res);
	}
	printf("%lld\n",splay.chkmax(splay.rt));
}
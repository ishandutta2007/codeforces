#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=5e3+51;
struct Edge{
	ll to,prev;
};
struct Query{
	ll x,y,k;
	inline bool operator <(const Query &rhs)const
	{
		return this->k<rhs.k;
	}
};
Edge ed[MAXN<<1];
Query qry[MAXN];
ll nc,tot,from,to,qcnt,x,y,z,hasSol,r;
ll last[MAXN],res[MAXN<<1];
vector<ll>s,ss;
vector<ll>bs[MAXN];
inline ll read()
{
    register ll num=0;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num;
} 
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void dfs(ll x,ll y,ll fa)
{
	if(x==y)
	{
		ss=s,hasSol=1;
		return;
	}
	for(register int i=last[x];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			s.push_back(i),dfs(ed[i].to,y,x),s.pop_back();
		}
	}
}
int main()
{
	nc=read(),memset(res,0x3f,sizeof(res));
	for(register int i=0;i<nc-1;i++)
	{
		from=read(),to=read();
		addEdge(from,to),addEdge(to,from);
	}
	qcnt=read();
	for(register int i=0;i<qcnt;i++)
	{
		qry[i].x=read(),qry[i].y=read(),qry[i].k=read();
	}
	sort(qry,qry+qcnt);
	for(register int i=0;i<qcnt;i++)
	{
		s.clear(),hasSol=0,dfs(qry[i].x,qry[i].y,0);
		bs[i]=ss;
		for(register int p=0;p<ss.size();p++)
		{
			ll j=ss[p];
			res[j]=res[((j+1)^1)-1]=qry[i].k;
		}
	}
	for(register int i=0;i<qcnt;i++)
	{
		r=0x3f3f3f3f,ss=bs[i];
		for(register int p=0;p<ss.size();p++)
		{
			ll j=ss[p];
			r=min(r,res[j]);
		}
		if(r!=qry[i].k)
		{
			puts("-1");
			return 0;
		}
	}
	for(register int i=1;i<=nc*2-2;i+=2)
	{
		cout<<(res[i]!=1061109567?res[i]:1000000)<<" ";
	} 
}
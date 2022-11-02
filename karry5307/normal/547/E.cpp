#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=5e5+51;
struct Edge{
	ll to,prev;
};
struct Query{
	ll l,r,kk,id;	
};
struct BIT{
	ll sz;
	ll num[MAXN];
	BIT()
	{
		memset(num,0,sizeof(num));
	}
	inline void add(ll pos,ll val)
	{
		for(;pos<=sz;pos+=pos&-pos)
		{
			num[pos]+=val;
		}
	}
	inline ll query(ll pos)
	{
		ll res=0;
		for(;pos;pos-=pos&-pos)
		{
			res+=num[pos];
		}
		return res;
	}
};
Edge ed[MAXN];
Query qry[MAXN];
BIT bit;
ll n,tot,qcnt,dfn;
ll last[MAXN],f[MAXN],l[MAXN],r[MAXN],dp[MAXN],res[MAXN];
string str[MAXN];
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
namespace ACAutomaton{
	const ll sigmaSize=26;
	queue<ll>q;
	struct ACAutomaton{
		ll trie[MAXN][sigmaSize],fail[MAXN],cnt;
		inline void insert(string str,ll ind)
		{
			ll length=str.length(),cur=0,num;
			for(register int i=0;i<length;i++)
			{
				num=str[i]-'a';
				if(!trie[cur][num])
				{
					trie[cur][num]=++cnt;
				}
				cur=trie[cur][num];
			}
			f[ind]=cur;
		}
		inline void create()
		{
			ll top;
			for(register int i=0;i<sigmaSize;i++)
			{
				if(trie[0][i])
				{
					fail[trie[0][i]]=0;
					q.push(trie[0][i]);
				}
			}
			while(!q.empty())
			{
				top=q.front(),q.pop();
				for(register int i=0;i<sigmaSize;i++)
				{
					if(trie[top][i])
					{
						fail[trie[top][i]]=trie[fail[top]][i],q.push(trie[top][i]);
					}
					else
					{
						trie[top][i]=trie[fail[top]][i];
					}
				}
			}
		}
	};
}
ACAutomaton::ACAutomaton AC;
inline void addEdge(ll from,ll to)
{
	ed[++tot].to=to;
	ed[tot].prev=last[from];
	last[from]=tot;
}
inline bool cmp(Query x,Query y)
{
	return x.r<y.r;
}
inline bool cmp2(Query x,Query y)
{
	return x.l<y.l;
}
inline void dfs(ll node)
{
	l[node]=++dfn;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		dfs(ed[i].to);
	}
	r[node]=dfn;
}
inline void calc()
{
	sort(qry+1,qry+qcnt+1,cmp);
	ll ptr=1,length,cur;
	for(register int i=1;i<=n;i++)
	{
		length=str[i].length(),cur=0;
		for(register int j=0;j<length;j++)
		{
			cur=AC.trie[cur][str[i][j]-'a'],bit.add(l[cur],1);
		}
		while(ptr<=qcnt&&qry[ptr].r==i)
		{
			res[qry[ptr].id]+=bit.query(r[f[qry[ptr].kk]])-bit.query(l[f[qry[ptr].kk]]-1);
			ptr++;
		}
	}
}
inline void calc2()
{
	memset(bit.num,0,sizeof(bit.num));
	sort(qry+1,qry+qcnt+1,cmp2);
	ll ptr=1,length,cur;
	while(ptr<=qcnt&&qry[ptr].l==0)
	{
		ptr++;
	}
	for(register int i=1;i<=n;i++)
	{
		length=str[i].length(),cur=0;
		for(register int j=0;j<length;j++)
		{
			cur=AC.trie[cur][str[i][j]-'a'],bit.add(l[cur],1);
		}
		while(ptr<=qcnt&&qry[ptr].l==i)
		{
			res[qry[ptr].id]-=(bit.query(r[f[qry[ptr].kk]])-bit.query(l[f[qry[ptr].kk]]-1));
			ptr++;
		}
	}
}
int main()
{
	n=read(),qcnt=read(); 
	for(register int i=1;i<=n;i++)
	{
		cin>>str[i],AC.insert(str[i],i);	
	}	
	AC.create();
	for(register int i=1;i<=AC.cnt;i++)
	{
		addEdge(AC.fail[i],i);
	}
	dfs(0),bit.sz=dfn;
	for(register int i=1;i<=qcnt;i++)
	{
		qry[i].l=read()-1,qry[i].r=read(),qry[i].kk=read(),qry[i].id=i;
	}
	calc(),calc2();
	for(register int i=1;i<=qcnt;i++)
	{
		printf("%lld\n",res[i]);
	} 
}
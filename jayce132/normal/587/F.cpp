#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;
const int M=310;
int n,q;

namespace SAM {

	struct node {
		int ch[26],len,fa;
	};
	node t[maxn<<1];
	int ttot=1,last[maxn],size[maxn<<1];
	inline void Init(){ memset(t,0,sizeof(node)*(ttot+1)); ttot=last[0]=1;}

	inline void Add(int x,int pos)
	{
		int np=last[pos]=++ttot,p=last[pos-1];
		t[np].len=t[p].len+1;
		while(p && !t[p].ch[x])t[p].ch[x]=np,p=t[p].fa;
		if(!p)t[np].fa=1;
		else {
			int q=t[p].ch[x];
			if(t[q].len==t[p].len+1)t[np].fa=q;
			else {
				int nq=++ttot; t[nq]=t[q];
				t[nq].len=t[p].len+1;
				t[np].fa=t[q].fa=nq;
				while(p && t[p].ch[x]==q)t[p].ch[x]=nq,p=t[p].fa;
			}
		}
	}

	inline void build_size(vector<char>str)
	{
		static int per[maxn<<1],tag[maxn];
		int n=SZ(str)-1;
		REP(i,0,n)tag[i]=0; REP(i,1,ttot)size[i]=0;
		REP(i,1,ttot)tag[t[i].len]++;
		REP(i,1,n)tag[i]+=tag[i-1];
		DREP(i,ttot,1)per[tag[t[i].len]--]=i;
		REP(i,1,n)size[last[i]]++;
		DREP(i,ttot,2)size[t[per[i]].fa]+=size[per[i]];
	}

};

vector<char>str[maxn];

struct Query {
	int pos,k,op,id;
};
Query qu1[maxn<<1],qu2[maxn<<1];
int q1tot,q2tot;
ll ans[maxn];

inline void init()
{
	n=read();q=read();
	REP(i,1,n)
	{
		static char S[maxn];
		scanf("%s",S+1); int len=strlen(S+1);
		str[i].push_back('0');
		REP(j,1,len)str[i].push_back(S[j]);
	}
	REP(i,1,q)
	{
		int l=read(),r=read(),k=read();
		if(SZ(str[k])>M)
		{
			qu2[++q2tot]=(Query){r,k,1,i};
			if(l>1)qu2[++q2tot]=(Query){l-1,k,-1,i};
		}else
		{
			qu1[++q1tot]=(Query){r,k,1,i};
			if(l>1)qu1[++q1tot]=(Query){l-1,k,-1,i};
		}
	}
}

inline void work2()
{
	static vector<int>to[maxn];
	REP(i,1,q2tot)to[qu2[i].k].push_back(i);
	
	REP(k,1,n)if(SZ(to[k])>=1)
	{
		SAM::Init();
		REP(j,1,SZ(str[k])-1)SAM::Add(str[k][j]-'a',j);
		SAM::build_size(str[k]);
		sort(to[k].begin(),to[k].end(),[](int a,int b){ return qu2[a].pos<qu2[b].pos;});
		int j=0; ll sum=0;
		REP(i,1,n)
		{
			int u=1;
			REP(l,1,SZ(str[i])-1)u=SAM::t[u].ch[str[i][l]-'a'];
			if(u)sum+=SAM::size[u];
			int id;
			while(j<SZ(to[k]) && (id=to[k][j],qu2[id].pos<=i))
			{
				ans[qu2[id].id]+=qu2[id].op*sum;
				j++;
			}
		}
	}
}

namespace ACautomaton {
	struct node {
		int ch[26],fail;
	};
	node t[maxn];
	int ttot=1;

	inline int insert(vector<char>str)
	{
		int len=SZ(str)-1;
		int u=1;
		REP(i,1,len)
		{
			int &v=t[u].ch[str[i]-'a'];
			if(!v)v=++ttot;
			u=v;
		}
		return u;
	}

	int dfn[maxn],low[maxn],times;
	vector<int>ed[maxn];
	
	void dfs(int u){ dfn[u]=++times; for(int v:ed[u])dfs(v); low[u]=times;}

	int blknum,blkpos[maxn],id[maxn];
	int val[maxn],ad[maxn];
	
	inline void get_fail()
	{
		REP(j,0,25)t[0].ch[j]=1; t[1].fail=0;
		queue<int>q;q.push(1);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			REP(i,0,25)
			{
				int &v=t[u].ch[i];
				if(v)t[v].fail=t[t[u].fail].ch[i],q.push(v);
				else v=t[t[u].fail].ch[i];
			}
		}
		REP(i,2,ttot)ed[t[i].fail].push_back(i);
		dfs(1);
		REP(i,1,ttot)id[i]=(i+M-1)/M;
		blknum=id[ttot];
		REP(i,1,blknum)blkpos[i]=min(i*M,ttot);
	}
	
	inline void update(int x)
	{
		int l=dfn[x],r=low[x];
		int idl=id[l],idr=id[r];
		if(idl==idr)REP(i,l,r)val[i]++;
		else {
			REP(i,l,blkpos[idl])val[i]++;
			REP(i,blkpos[idr-1]+1,r)val[i]++;
			idl++; idr--;
			REP(i,idl,idr)ad[i]++;
		}
	}

	inline int ask(int x){ return val[dfn[x]]+ad[id[dfn[x]]];}
};
int be[maxn];

using ACautomaton::insert;
using ACautomaton::get_fail;
using ACautomaton::update;
using ACautomaton::ask;

inline void work1()
{
	REP(i,1,n)be[i]=insert(str[i]);
	get_fail();
	sort(qu1+1,qu1+q1tot+1,[](Query a,Query b){ return a.pos<b.pos;});
	int j=1;
	REP(i,1,n)
	{
		update(be[i]); 
		while(j<=q1tot && qu1[j].pos<=i)
		{
			int u=1;
			int x=qu1[j].k;
			REP(l,1,SZ(str[x])-1)
			{
				u=ACautomaton::t[u].ch[str[x][l]-'a'];
				ans[qu1[j].id]+=qu1[j].op*ask(u);
			}
			j++;
		}
	}
}

inline void doing()
{
	work2();
	work1();
	REP(i,1,q)printf("%lld\n",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF587F.in","r",stdin);
	freopen("CF587F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
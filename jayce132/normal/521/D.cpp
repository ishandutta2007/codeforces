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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;

int k,n,m;
ll a[maxn];
pair<int,int> mx[maxn];

int OP[maxn];

struct Quest {
	int op,id,b,RID;
};
Quest qu[maxn];
int qtot;

struct node {
	double prod;
	int id,op,RID;
	node(double _prod=0,int _id=0,int _op=0,int _RID=0){ prod=_prod; id=_id; op=_op; RID=_RID;}
};
inline bool operator < (node a,node b){ return a.prod==b.prod?a.op<b.op:a.prod<b.prod;}

priority_queue<node>Qall;
vector<node>Q[maxn];

inline void init()
{
	k=read();n=read();m=read();
	REP(i,1,k)a[i]=read();
	REP(i,1,n)
	{
		int op=read(),id=read(),b=read();
		OP[i]=op;
		if(op==2 || (op==3 && b>1))qu[++qtot]=(Quest){op,id,b,i};
		if(op==1)chkmax(mx[id],mkr(b,i));
	}
	REP(i,1,k)if(mx[i].fi>a[i])qu[++qtot]=(Quest){2,i,mx[i].fi-a[i],mx[i].se};
	REP(i,1,qtot)
	{
		int id=qu[i].id;
		if(qu[i].op==3)Qall.push(node(qu[i].b,qu[i].id,qu[i].op,qu[i].RID));
		else if(qu[i].op==2)Q[qu[i].id].push_back(node(qu[i].b,id,qu[i].op,qu[i].RID));
	}
	REP(i,1,k)sort(Q[i].begin(),Q[i].end());
	
	REP(i,1,k)if(!Q[i].empty())
	{
		node x=Q[i].back();
		Qall.push(node(1+x.prod/a[i],x.id,x.op,x.RID));
	}
}

vector<int>ans;

inline void doing()
{
	while(m-- && !Qall.empty())
	{
		node x=Qall.top(); Qall.pop();
		ans.push_back(x.RID);
		if(x.op==2)
		{
			int id=x.id;
			a[id]+=(int)Q[id].back().prod;
			Q[id].pop_back();
			node x=Q[id].back();
			if(!Q[id].empty())Qall.push(node(1+x.prod/a[id],x.id,x.op,x.RID));
		}
	}
	sort(ans.begin(),ans.end(),[](int a,int b){ return OP[a]<OP[b];});
	printf("%d\n",SZ(ans));
	REP(i,0,SZ(ans)-1)printf("%d ",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF521D.in","r",stdin);
	freopen("CF521D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
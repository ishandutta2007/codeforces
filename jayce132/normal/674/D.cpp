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

inline void myassert(bool a,string s)
{
	if(!a)cerr<<s<<endl,exit(0);
}

int n,q;
int a[maxn];
ll b[maxn];
ll e[maxn],c[maxn];
int d[maxn];

struct Heap1 {
	priority_queue<ll>p,q;
	inline void check(){ while(myassert(!(p.empty() && !q.empty()),"Heap1"),!q.empty() && p.top()==q.top())p.pop(),q.pop();}
	inline void push(ll x){ p.push(x); check();}
	inline void pop(){ p.pop(); check();}
	inline ll top(){ return p.top();}
	inline void del(ll x){ q.push(x); check();}
	inline bool empty(){ return p.empty();}
}MAX,mx[maxn];


struct Heap2 {
	priority_queue<ll,vector<ll>,greater<ll> >p,q; 
	inline void check(){ while(myassert(!(p.empty() && !q.empty()),"Heap2"),!q.empty() && p.top()==q.top())p.pop(),q.pop();}
	inline void push(ll x){ p.push(x);check();}
	inline void pop(){ p.pop(); check();}
	inline ll top(){ return p.top();}
	inline void del(ll x){ q.push(x); check();}
	inline bool empty(){ return p.empty();}
}MIN,mn[maxn];

inline void init()
{
	n=read();q=read();
	REP(i,1,n)scanf("%lld",&b[i]);
	REP(i,1,n)a[i]=read(),d[i]+=2,d[a[i]]++;
	REP(i,1,n)e[i]=b[i]/d[i];
	REP(i,1,n)c[i]+=b[i]-d[i]*e[i]+e[i],c[a[i]]+=e[i];
	//REP(i,1,n)s.insert(c[i]);
	REP(i,1,n)mx[a[i]].push(c[i]),mn[a[i]].push(c[i]);
	REP(i,1,n)if(!mx[i].empty())MAX.push(mx[i].top()+e[i]);
	REP(i,1,n)if(!mn[i].empty())MIN.push(mn[i].top()+e[i]);
}

int vis[maxn];

inline void DEL(int x)
{
	if(vis[x])return;
	vis[x]=1;
	MIN.del(mn[a[x]].top()+e[a[x]]);
	MAX.del(mx[a[x]].top()+e[a[x]]);
	mn[a[x]].del(c[x]); mx[a[x]].del(c[x]);
	if(!mn[a[x]].empty())MIN.push(mn[a[x]].top()+e[a[x]]);
	if(!mx[a[x]].empty())MAX.push(mx[a[x]].top()+e[a[x]]);

}

inline void ADD(int x)
{
	if(!vis[x])return;
	vis[x]=0;
	if(!mn[a[x]].empty())MIN.del(mn[a[x]].top()+e[a[x]]);
	if(!mx[a[x]].empty())MAX.del(mx[a[x]].top()+e[a[x]]);
	mn[a[x]].push(c[x]); mx[a[x]].push(c[x]);
	MIN.push(mn[a[x]].top()+e[a[x]]);
	MAX.push(mx[a[x]].top()+e[a[x]]);
}

inline void CG(int x,ll y)
{
	MIN.del(mn[x].top()+e[x]);
	MAX.del(mx[x].top()+e[x]);
	MIN.push(mn[x].top()+y);
	MAX.push(mx[x].top()+y);
}


inline void doing()
{
	REP(i,1,q)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read(),z=a[x];

			DEL(z); DEL(y);
			DEL(a[z]);
			DEL(a[y]);
			DEL(x);
			
			c[z]-=b[z]-d[z]*e[z]+e[z]; c[y]-=b[y]-d[y]*e[y]+e[y];
			c[a[z]]-=e[z]; c[a[y]]-=e[y]; c[z]-=e[x];
			d[y]++; d[z]--; 
			
			if(!mn[y].empty())CG(y,b[y]/d[y]);
			if(!mn[z].empty())CG(z,b[z]/d[z]);
			e[y]=b[y]/d[y]; e[z]=b[z]/d[z];
			
			c[z]+=b[z]-d[z]*e[z]+e[z]; c[y]+=b[y]-d[y]*e[y]+e[y];
			c[a[z]]+=e[z]; c[a[y]]+=e[y]; c[y]+=e[x];
			a[x]=y;

			ADD(z); ADD(y);
			ADD(a[z]);
			ADD(a[y]);
			ADD(x);
		}
		else if(op==2)
		{
			int x=read();
			printf("%lld\n",c[x]+e[a[x]]);
		}else
		{
			//cerr<<MAX.top()<<endl;
			printf("%lld %lld\n",MIN.top(),MAX.top());
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF674D.in","r",stdin);
	freopen("CF674D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
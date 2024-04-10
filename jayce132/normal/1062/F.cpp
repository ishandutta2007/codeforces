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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=3e5+20;

int n,m;
vector<int>out[maxn],in[maxn];
int rd[maxn];

inline void init()
{
    n=read();m=read();
    REP(i,1,m)
    {
	int u=read(),v=read();
	out[u].push_back(v);
	in[v].push_back(u);
    }
}

deque<int>q;
int ans[maxn];
int rk[maxn],tp;

inline void doing()
{
    REP(i,1,n)rd[i]=SZ(in[i]);
    int rest=n;
    REP(i,1,n)if(!rd[i])q.push_back(i),rest--;
    while(!q.empty())
    {
	int u=q.front();
	if(SZ(q)>2)ans[u]+=0;
	else if(SZ(q)==1)ans[u]+=rest;
	else {
	    int x=q.back();
	    int flg=0;
	    for(int y:out[x])if(rd[y]==1)flg=1;
	    if(!flg)ans[u]+=rest;
	}
	q.pop_front();
	for(int v:out[u])
	    if(!(--rd[v]))q.push_back(v),rest--;
    }
    rest=n;
    REP(i,1,n)rd[i]=SZ(out[i]);
    REP(i,1,n)if(!rd[i])q.push_back(i),rest--;
    while(!q.empty())
    {
	int u=q.front();
	if(SZ(q)>2)ans[u]+=0;
	else if(SZ(q)==1)ans[u]+=rest;
	else {
	    int x=q.back();
	    int flg=0;
	    for(int y:in[x])if(rd[y]==1)flg=1;
	    if(!flg)ans[u]+=rest;
	}
	q.pop_front();
	for(int v:in[u])
	    if(!(--rd[v]))q.push_back(v),rest--;
    }
    int Ans=0;
    REP(i,1,n)if(ans[i]>=n-2)Ans++;
    printf("%d\n",Ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}
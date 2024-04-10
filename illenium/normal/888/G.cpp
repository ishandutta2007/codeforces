#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 2e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,a[maxn],cnt=1;
ll ans,Q;
vector <int> p;
struct node{int nxt[2],w;}t[maxn*30];

inline void ins(int u,int x,int dep,int w)
{
	t[u].w+=w; if(dep==-1) return;
	int tmp=(x&(1<<dep))?1:0;
	if(!t[u].nxt[tmp]) t[u].nxt[tmp]=++cnt;
	ins(t[u].nxt[tmp],x,dep-1,w);
}

inline void query(int u,int x,int dep)
{
	if(dep==-1) return; int tmp=(x&(1<<dep))?1:0;
	if(t[t[u].nxt[tmp]].w) query(t[u].nxt[tmp],x,dep-1);
	else Q+=(1<<dep),query(t[u].nxt[tmp^1],x,dep-1);
}

inline void dfs(vector <int> v,int dep)
{
	if(dep==-1) return;
	vector <int> v0,v1; v0.clear(); v1.clear();
	for(auto x:v) if(x&(1<<(dep))) v1.pb(x); else v0.pb(x);
	if(v0.size()&&v1.size())
	{
		ans+=(1<<dep); ll ANS=inf;
		for(auto x:v0) ins(1,x,30,1);
		for(auto x:v1) Q=0,query(1,x^(1<<dep),30),ANS=min(ANS,Q);
		for(auto x:v0) ins(1,x,30,-1); ans+=ANS;
	}
	if(v0.size()) dfs(v0,dep-1); if(v1.size()) dfs(v1,dep-1);
}

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),p.pb(a[i]);
	dfs(p,29); cout<<ans<<endl;
	return 0;
}
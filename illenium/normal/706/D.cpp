//CF 706D
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int ct,ans;
struct node{int nxt[2],w;}t[maxn*30];

inline void ins(int u,int x,int dep,int w)
{
	t[u].w+=w; int tmp=0; if(dep==-1) return;
	if(x&(1<<dep)) tmp=1; else tmp=0;
	if(!t[u].nxt[tmp]) t[u].nxt[tmp]=++ct;
	ins(t[u].nxt[tmp],x,dep-1,w);
}

inline void query(int u,int x,int dep)
{
	if(dep==-1) return;
	if(x&(1<<dep))
	{
		if(t[u].nxt[0]&&t[t[u].nxt[0]].w) ans+=(1<<dep),query(t[u].nxt[0],x,dep-1);
		else query(t[u].nxt[1],x,dep-1);
	}
	else
	{
		if(t[u].nxt[1]&&t[t[u].nxt[1]].w) ans+=(1<<dep),query(t[u].nxt[1],x,dep-1);
		else query(t[u].nxt[0],x,dep-1);
	}
}

int main()
{
	//freopen("t1.in","r",stdin);
	int Q=read(); ins(0,0,30,1);
	while(Q--)
	{
		char opt; scanf("%c",&opt); int x=read();
		if(opt=='+') ins(0,x,30,1);
		else if(opt=='-') ins(0,x,30,-1);
		else ans=0,query(0,x,30),printf("%d\n",ans);
	}
	return 0;
}
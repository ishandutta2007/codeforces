#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
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

vector <int> mp[maxn],q;
int dep[maxn],x,y,x2,n,rt,pre;
char s[maxn];

inline void dfs(int u,int fa)
{
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i]; if(v==fa) continue;
		dep[v]=dep[u]+1; dfs(v,u);
	}
}

inline bool jud(int Q)
{
	q.clear(); rep(i,1,n) if(dep[i]==Q) q.pb(i);
	printf("? %d ",q.size());
	rep(i,0,q.size()-1) printf("%d ",q[i]); puts(""); fflush(stdout);
	x=read(); int tmp=read();
	if(tmp==y) {pre=x; return true;} return false;
}

int main()
{
	//freopen("t1.in","r",stdin);
	int T=read();
	while(T--)
	{
		n=read(); rep(i,1,n) mp[i].clear();
		rep(i,1,n-1) {int u=read(),v=read(); mp[u].pb(v); mp[v].pb(u);}
		printf("? %d ",n); rep(i,1,n) printf("%d ",i); puts(""); fflush(stdout);
		rt=read(); y=read(); dep[rt]=0; dfs(rt,0); int mx=0;
		rep(i,1,n) mx=max(mx,dep[i]);
		int l=0,r=mx,ans;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(jud(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		dep[pre]=0; dfs(pre,0); q.clear(); rep(i,1,n) if(dep[i]==y) q.pb(i);
		printf("? %d ",q.size());
		rep(i,0,q.size()-1) printf("%d ",q[i]); puts(""); fflush(stdout);
		int x2=read(),y=read(); printf("! %d %d\n",pre,x2); fflush(stdout);
		scanf("%s",s+1);
	}
	return 0;
}
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
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

int a[maxn],b[maxn],vis[maxn],p[maxn],ans,n,cnt;
stack <int> s;

inline void dfs(int u)
{
	p[++cnt]=u; vis[u]=1;
	if(vis[a[u]]) return; dfs(a[u]);
}

inline bool jud(int u)
{
	//rep(i,1,cnt) cout<<p[i]<<" "; cout<<endl;
	int z=cnt/u;
	for(int i=1;i<=u;i++)
	{
		int f=0;
		for(int j=i,q=1;q<=z;q++,j=(j+u)%cnt)
		{
			if(j==0) j=cnt;
			if(b[p[j]]!=b[p[i]]) {f=1; break;}
		}
		if(f==0) return true;
	}
	return false;
}

inline void wk()
{
	for(int i=1;i*i<=cnt;i++)
	{
		if(cnt%i==0)
		{
			if(jud(i)) ans=min(ans,i);
			if(jud(cnt/i)) ans=min(ans,cnt/i);
		}
	}
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); rep(i,1,n) a[i]=read(); rep(i,1,n) b[i]=read();
		ans=inf; rep(i,1,n) vis[i]=0;
		rep(i,1,n) if(!vis[i])
		{
			dfs(i),wk(),cnt=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
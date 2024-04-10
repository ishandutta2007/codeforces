#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int f[maxn],cnt[maxn],ed[maxn],ans;
bool vis[maxn];

inline int getf(int x)
{
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}

inline void mer(int a,int b)
{
	int fa=getf(a),fb=getf(b);
	if(fa!=fb) f[fa]=fb;
}

int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		mer(u,v);
	}
	for(int i=1;i<=n;i++) f[i]=getf(i);
	for(int i=1;i<=n;i++) cnt[f[i]]++;
	for(int i=n;i>=1;i--) if(ed[f[i]]==0) ed[f[i]]=i;
	for(int i=1;i<=n;i++)
	{
		if(cnt[f[i]]==1||vis[f[i]]==1)
		{
			vis[f[i]]=1;
			continue;
		}
		else
		{
			vis[f[i]]=1; int tmpp=ed[f[i]];
			for(int j=1;j<=tmpp;j++)
			{
				if(vis[f[j]]==0)
				{
					vis[f[j]]=1;
					tmpp=max(tmpp,ed[f[j]]);
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
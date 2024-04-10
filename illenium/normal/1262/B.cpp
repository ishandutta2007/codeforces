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

int a[maxn],ans[maxn];
bool vis[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),cnt=0,fl=0,mx=0;
		for(int i=1;i<=n;i++) a[i]=read();
		ans[1]=a[1]; vis[a[1]]=1;
		for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) ans[i]=a[i],vis[a[i]]=1;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]) continue;
			else
			{
				cnt++;
				while(vis[cnt]==1) cnt++;
				ans[i]=cnt;
			}
		}
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,ans[i]);
			if(mx!=a[i]) {fl=1; break;}
		}
		if(fl==1) printf("-1");
		else for(int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
		for(int i=1;i<=n;i++) ans[i]=0,vis[i]=0;
	}
	return 0;
}
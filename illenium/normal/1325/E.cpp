#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

struct node{int to,id;};
vector <node> mp[maxn];
int vis[maxn],n,a[maxn],inq[maxn],dis[maxn],cnt;

inline int bfs(int fs)
{
	queue <int> q; q.push(fs);
	int tmp=inf;
	for(int i=1;i<=1000;i++) dis[i]=0; inq[fs]=fs;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			node v=mp[u][i];
			if(vis[v.id]==fs) continue;
			if(inq[v.to]==fs) tmp=min(tmp,dis[v.to]+dis[u]+1);
			else
			{
				inq[v.to]=fs,dis[v.to]=dis[u]+1,vis[v.id]=fs;
				q.push(v.to);
			}
		}
	}
	return tmp;
} 

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) if((int)sqrt(a[i])*(int)sqrt(a[i])==a[i]) {puts("1"); return 0;}
	for(int i=1;i<=n;i++)
	{
		int f1=0,f2=0,nw=0;
		for(int j=2;j*j<=a[i];j++)
		{
			nw=0;
			if(a[i]%j==0)
			{
				nw=0;
				while(a[i]%j==0) a[i]/=j,nw^=1;
			}
			if(nw==1&&f1==0) f1=j;
			else if(nw==1) f2=j;
		}
		if(a[i]!=1)
		{
			if(f1==0) f1=a[i];
			else f2=a[i];
		}
		if(f2==0) mp[1].push_back({f1,++cnt}),mp[f1].push_back({1,cnt});
		else mp[f2].push_back({f1,++cnt}),mp[f1].push_back({f2,cnt});
	}
	int ans=inf;
	for(int i=1;i<=1000;i++) ans=min(ans,bfs(i));
	if(ans==inf) puts("-1"); else cout<<ans<<endl;
	return 0;
}
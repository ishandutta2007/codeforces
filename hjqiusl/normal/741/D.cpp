// Problem: D. Arpas letter-marked tree and Mehrdads Dokhtar-kosh paths
// Contest: Codeforces - Codeforces Round #383 (Div. 1)
// URL: https://codeforces.com/problemset/problem/741/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> e[500003];
int a[500003],d[500003],sz[500003],son[500003],ans[500003],f[1<<22];
void dfs1(int x)
{
	sz[x]=1;
	for(int y:e[x]) 
		d[y]=d[x]+1,a[y]^=a[x],dfs1(y),
		sz[x]+=sz[y],(sz[y]>sz[son[x]])&&(son[x]=y);
	return ;
}
void clr(int x)
{
	f[a[x]]=0xc0c0c0c0;
	for(int y:e[x]) clr(y);
	return ;
}
void calc(int x,int t)
{
	(ans[t]<f[a[x]]+d[x])&&(ans[t]=f[a[x]]+d[x]);
	for(int i=0; i<22; ++i) 
		(ans[t]<f[a[x]^(1<<i)]+d[x])&&(ans[t]=f[a[x]^(1<<i)]+d[x]);
	for(int y:e[x]) calc(y,t);
	return ;
}
void upd(int x)
{
	(f[a[x]]<d[x])&&(f[a[x]]=d[x]);
	for(int y:e[x]) upd(y);
	return ;
}
void dfs2(int x)
{
	for(int y:e[x]) if(y!=son[x]) dfs2(y),clr(y);
	if(son[x]) dfs2(son[x]);
	for(int y:e[x]) if(y!=son[x]) calc(y,x),upd(y);
	(ans[x]<f[a[x]]+d[x])&&(ans[x]=f[a[x]]+d[x]);
	for(int i=0; i<22; ++i) 
		(ans[x]<f[a[x]^(1<<i)]+d[x])&&(ans[x]=f[a[x]^(1<<i)]+d[x]);
	(f[a[x]]<d[x])&&(f[a[x]]=d[x]);
	return ;
}
signed main()
{
	memset(f,0xc0,sizeof(f));
	int n=read();
	
	for(int i=2; i<=n; ++i) e[read()].push_back(i),a[i]=1<<(getchar()-'a');
	dfs1(1);
	for(int i=1; i<=n; ++i) ans[i]=d[i]<<1;
	dfs2(1);
	for(int i=n; i>=1; --i)
	{
		ans[i]-=d[i]<<1;
		for(int j:e[i]) ans[i]=max(ans[i],ans[j]);
	}
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=300005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,u,v,head[N],Next[N*2],adj[N*2],o,k,dep[N];
int siz[N],a[N];
long long s;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j;
	siz[i]=1;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
		{
			dep[adj[j]]=dep[i]+1;
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
		}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&o);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	dfs(1,0);
	for(i=1;i<=n;++i)
		a[i]=dep[i]-(siz[i]-1);
	sort(a+1,a+1+n);
	for(i=n;i>n-o;--i)
		s+=a[i];
	cout<<s;
}
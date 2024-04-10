#include<bits/stdc++.h>
using namespace std;
vector<int> G[330];
int leaf[330],p;
int route[660000],pr;
int father[330];
int depth[330];
void dfs(int x,int fa)
{
	if(fa==-1)
		depth[x]=0;
	else	depth[x]=depth[fa]+1;
	father[x]=fa;
	for(int i=0;i<(G[x].size());i++)
		if(G[x][i]!=fa)
			dfs(G[x][i],x);
	return ;
}
int lca(int a,int b)
{
	if(depth[a]>depth[b])
		return lca(b,a);
	while(depth[b]>depth[a])
		b=father[b];
	while(a!=b)
	{
		a=father[a];
		b=father[b];
	}
	return a;
}
void up(int a,int b)
{
	while(a!=b)
	{
		a=father[a];
		route[pr++]=a;
	}
}
bool findd;
void down(int a,int b)
{
	//cout<<"downing..."<<a<<" "<<b<<endl;
	if(a==b)
	{
		findd=true;
		return ;
	}
	int tmpr=pr;
	for(int i=0;i<(G[a].size());i++)
		if(G[a][i]!=father[a])
		{
			route[pr++]=G[a][i];
			down(G[a][i],b);
			if(findd)
				return ;
			pr=tmpr;
		}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	while(cin>>leaf[p])
	{
		leaf[p]--;
		p++;
	}
	dfs(0,-1);
	pr++;
	findd=false;
	down(0,leaf[0]);
	for(int i=0;i<p-1;i++)
	{
		findd=false;
		up(leaf[i],lca(leaf[i],leaf[i+1]));
		down(lca(leaf[i],leaf[i+1]),leaf[i+1]);
	}
	up(leaf[p-1],0);
	if(pr!=n+n-1)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<pr;i++)
		cout<<route[i]+1<<" ";
	return 0;
}
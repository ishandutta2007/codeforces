#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> G[50050];
int sz[50050];
int father[50050];
bool del[50050];
int n,k;
void refresh(int x,int fa)
{
	father[x]=fa;
	sz[x]=1;
	for(int i=0;i<(int)(G[x].size());i++)
		if(G[x][i]!=fa&&!del[G[x][i]])
		{
			refresh(G[x][i],x);
			sz[x]+=sz[G[x][i]];
		}
	return ;
}
int get_centroid(int x,int fa,int treesize)
{
	for(int i=0;i<(int)(G[x].size());i++)
		if(G[x][i]!=fa)
			if(sz[G[x][i]]>treesize/2&&!del[G[x][i]])
				return get_centroid(G[x][i],x,treesize);
	return x;
}
void get_distance(int x,int fa,vector<int> &Dist,int dist,int limit)
{
	Dist[dist]++;
	if(dist==limit)
		return ;
	for(int i=0;i<(int)(G[x].size());i++)
		if(G[x][i]!=fa&&!del[G[x][i]])
			get_distance(G[x][i],x,Dist,dist+1,limit);
	return ;
}
ll dfs(int root)
{
	if(del[root])
		return 0ll;
//	cout<<"decomposition starts:\n";
//	cout<<"root:"<<root<<endl;
	refresh(root,0);
	if(sz[root]==1)
	{
//		puts("decomposition stops(component size is too small)");
		return 0ll;
	}
	int centroid=get_centroid(root,0,sz[root]);
//	cout<<"centroid:"<<centroid<<endl;
	vector<int> dist(k+1,0);
	get_distance(centroid,0,dist,0,k);
//	cout<<"distance:\n";
//	cout<<"dist\tcount\n";
//	for(int i=0;i<=k;i++)
//		cout<<i<<"\t"<<dist[i]<<endl;
	ll ret=0;
	for(int i=0;i<=(k-1)/2;i++)
		ret+=1ll*dist[i]*dist[k-i];
	if(k%2==0)
		ret+=1ll*dist[k/2]*(dist[k/2]-1)/2;
	for(int i=0;i<(int)(G[centroid].size());i++)
		if(!del[G[centroid][i]])
		{
			int to=G[centroid][i];
			vector<int> Dist(k+1,0);
			get_distance(to,centroid,Dist,1,k);
			for(int i=1;i<=(k-1)/2;i++)
				ret-=1ll*Dist[i]*Dist[k-i];
			if(k%2==0)
				ret-=1ll*Dist[k/2]*(Dist[k/2]-1)/2;
		}
	del[centroid]=true;
	for(int i=0;i<(int)(G[centroid].size());i++)
		if(G[centroid][i]!=father[centroid]&&!del[G[centroid][i]])
			ret+=dfs(G[centroid][i]);
	ret+=dfs(root);
//	puts("decomposition stops");
	return ret;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cout<<dfs(1)<<endl;
	return 0;
}
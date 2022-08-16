#include <bits/stdc++.h>
#define ll long long
#define upperlimit 10010
using namespace std;
int n,m;
bool f=false;
vector <int> adj[upperlimit+1];
bool visited[upperlimit+1];
void dfs(int node){
	visited[node]=true;
	int i;
	for(i=0;i<adj[node].size();i++)if(!visited[adj[node][i]])dfs(adj[node][i]);
}
bool connected()
{
	int i;
	for(i=1;i<=n;i++)visited[i]=false;
	dfs(1);
	for(i=1;i<=n;i++)if(!visited[i])return false;
	return true;
}
void traverse(int node,int parent)
{
	visited[node]=true;
	int i;
	for(i=0;i<adj[node].size();i++){
		if(adj[node][i]==node)f=true;
		if(!visited[adj[node][i]]){
			traverse(adj[node][i],node);
		}
		else{
			if(adj[node][i]!=parent)f=true;
		}
	}
}
void cycle()
{
	int i;
	for(i=1;i<=n;i++)visited[i]=false;
	for(i=1;i<=n;i++)if(!visited[i])traverse(i,-1);
}
int main()
{
	int i,j;
	int l,r;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>l>>r;
		adj[l].push_back(r);
		adj[r].push_back(l);
	}
	cycle();
	if(connected()&&n==m+1)cout<<"yes";
	else cout<<"no";
}
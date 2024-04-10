#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int cnt;
bool vis[1010];
vector<int> G[1010];
void dfs(int x)
{
	vis[x]=true;
	cnt++;
	for(int i=0;i<(int)(G[x].size());i++)
		if(!vis[G[x][i]])
			dfs(G[x][i]);
}
int Cap[1010];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
		cin>>Cap[i];
	vector<int> sz;
	int lft=n;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	for(int i=0;i<k;i++)
	{
		cnt=0;
		dfs(Cap[i]);
		sz.pb(cnt);
		lft-=cnt;
	}
	sort(sz.rbegin(),sz.rend());
	sz[0]+=lft;
	long long ans=0;
	for(int i=0;i<k;i++)
		ans+=1ll*sz[i]*(sz[i]-1)/2ll;
	ans-=m;
	cout<<ans<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[200200];
int d[200200][2];
void dfs(int x,int fa,int dep,bool p)
{
	d[x][p]=dep;
	for(int i=0;i<(int)(G[x].size());i++)
		if(fa!=G[x][i])
			dfs(G[x][i],x,dep+1,p);
}
int main()
{
	int n,b;
	cin>>n>>b;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0,0,0);
	dfs(b,0,0,1);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(d[i][0]>d[i][1])
			ans=max(ans,d[i][0]*2);
	cout<<ans<<endl;
	return 0;
}
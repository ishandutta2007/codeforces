#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
bool visited[200001];
pair<int ,bool> dfs(int i,int j,vector<int> gra[],int o)
{
	int s=1;
	pair<int,bool> r;
	r.second=false;
	visited[i]=true;
	bool a=false;
	FOR(k,0,gra[i].size())
	{
		if(gra[i][k]!=j && visited[gra[i][k]]==false)
		{
			r=dfs(gra[i][k],i,gra,o);
			s+=r.first;
			a=(r.second | a);
		}
	}
	if(i==o)
	a=true;
	return mp(s,a);
}
ll dfh(int a,int n,int b,vector<int> gra[])
{
	pair<int,int> r;
	visited[a]=true;
	FOR(i,0,gra[a].size())
	{
		r=dfs(gra[a][i],a,gra,b);
		if(r.second)
		return r.first;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--)
	{
		int n,m,a,b;
		ll l,r;
		ll ans;
		cin>>n>>m>>a>>b;
		vector<int> gra[n];
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			gra[u-1].pb(v-1);
			gra[v-1].pb(u-1);
		}
		FOR(i,0,n)visited[i]=false;
		l=n-dfh(a-1,n,b-1,gra)-1;
		FOR(i,0,n)visited[i]=false;
		r=n-dfh(b-1,n,a-1,gra)-1;
		ans=l*r;
		cout<<ans<<'\n';
	}
	return 0;
}
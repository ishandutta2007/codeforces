#include<bits/stdc++.h>
using namespace std;
const int Maxn=300005;
bool vis[Maxn],color[Maxn],bad;
vector<int> G[Maxn];
int X[Maxn],Y[Maxn];
int N,M,C[2];
const long long mod=998244353;
void dfs_color(int x,bool col)
{
	if(vis[x])
	{
		if(col!=color[x])
			bad=1;
		return ;
	}
	color[x]=col;
	C[col]++;
	col^=1;//^-
	//col=1-col;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
		dfs_color(G[x][i],col);
	return ;
}
long long Mi(int N)
{
	long long ans=1;
	long long x=2;
	while(N)
	{
		if(N%2==0)
			x=x*x%mod;
		else
		{
			ans=ans*x%mod;
			x=x*x%mod;
		}
		N/=2;
	}
	return ans;
}
int MAIN()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		G[i].resize(0),
		vis[i]=color[i]=0;
	for(int i=0;i<M;i++)
	{
		cin>>X[i]>>Y[i];
		G[X[i]].push_back(Y[i]);
		G[Y[i]].push_back(X[i]);
	}
	long long ans=1;
	for(int i=1;i<=N;i++)
		if(!vis[i])
		{
			bad=0;
			C[0]=C[1]=0;
			dfs_color(i,0);
			if(!bad)
				ans=ans*((Mi(C[0])+Mi(C[1]))%mod)%mod;
			else
			{
				puts("0");
				return 0;
			}
		}
	cout<<ans<<endl;
	return 0;
}
int main()	
{
	int T;
	cin>>T;
	while(T--)
		MAIN();
	return 0;
}
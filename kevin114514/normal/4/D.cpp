#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int dp[5050];
vector<int> Topo;
int deg[5050];
int Prev[5050];
int h[5050],w[5050];
int main()
{
	int N,H,W;
	cin>>N>>H>>W;
	h[0]=H;
	w[0]=W;
	for(int i=1;i<=N;i++)
		cin>>h[i]>>w[i];
	N++;
//	puts("ur shit out");
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(h[i]<h[j]&&w[i]<w[j])
			{
				deg[i]++;
			}
	queue<int> Q;
	for(int i=0;i<N;i++)
		if(!deg[i])
		{
			Topo.pb(i);
			Q.push(i);
		}
//	puts("fuck off");
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=0;i<N;i++)
		if(h[u]>h[i]&&w[u]>w[i])
		{
			int v=i;
			deg[v]--;
			if(!deg[v])
			{
				Q.push(v);
				Topo.pb(v);
			}
		}
	}
//	puts("bitch");
	memset(Prev,-1,sizeof(Prev));
	for(int i=0;i<N;i++)
	{
		int u=Topo[i];
		for(int j=0;j<N;j++)
		if(h[u]>h[j]&&w[u]>w[j])
		{
			int v=j;
			if(dp[u]+1>dp[v])
			{
				dp[v]=dp[u]+1;
				Prev[v]=u;
			}
		}
	}
	cout<<dp[0]<<endl;
	int x=Prev[0];
	while(x>=0)
	{
		cout<<x<<" ";
		x=Prev[x];
	}
	return 0;
}
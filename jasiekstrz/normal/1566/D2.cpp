#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=300;
const int NM=(N+10)*(N+10);
pair<int,int> t[NM+10];
bool vis[N+10][N+10];
pair<int,int> st[NM+10];
vector<pair<int,int>> av;
long long solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>t[i].fi;
		t[i].se=i;
	}
	sort(t+1,t+n*m+1);
	for(int i=1;i<=n*m;)
	{
		int k;
		av.clear();
		for(k=i;k<=n*m && t[k].fi==t[i].fi;k++)
			av.emplace_back((k-1)/m+1,-((k-1)%m+1));
		sort(av.begin(),av.end());
		for(int j=i,it=0;j<k;j++,it++)
		{
			st[t[j].se]={av[it].fi,-av[it].se};
		}
		i=k;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			vis[i][j]=false;
	}
	long long ans=0;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=st[i].se;j++)
		{
			if(vis[st[i].fi][j])
				ans++;
		}
		vis[st[i].fi][st[i].se]=true;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		cout<<solve()<<"\n";
	return 0;
}
#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int indeg[200200],outdeg[200200];
vector<int> G[200200];
int ind[200200];
int dp[200200];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		ind[v]++;
		indeg[v]++;
		outdeg[u]++;
	}
	vector<int> vec;
	queue<int> que;
	for(int i=1;i<=n;i++)
		if(!ind[i])
			que.push(i);
	while(!que.empty())
	{
		int x=que.front();
		que.pop();
		vec.pb(x);
		for(auto y:G[x])
		{
			ind[y]--;
			if(!ind[y])
				que.push(y);
		}
	}
	rev(vec);
	for(auto x:vec)
	{
		dp[x]=1;
		if(outdeg[x]<=1)
			continue;
		for(auto y:G[x]) if(indeg[y]!=1)
			dp[x]=max(dp[x],dp[y]+1);
	}
	cout<<*max_element(dp+1,dp+n+1)<<endl;
	return 0;
}
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
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[200100];
int dp[200100];
int deg[200100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			dp[i]=0;
			deg[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int need;
			cin>>need;
			while(need--)
			{
				int x;
				cin>>x;
				G[x].pb(i);
				deg[i]++;
			}
		}
		queue<int> q;
		for(int i=1;i<=n;i++)
			if(!deg[i])
			{
				q.push(i);
				dp[i]=1;
			}
		int cnt=0;
		while(!q.empty())
		{
			cnt++;
			int x=q.front();
			q.pop();
			for(int i=0;i<sz(G[x]);i++)
			{
				int v=G[x][i];
				dp[v]=max(dp[v],dp[x]+(bool)(x>v));
				deg[v]--;
				if(!deg[v])
					q.push(v);
			}
		}
		if(cnt!=n)
			puts("-1");
		else	cout<<*max_element(dp+1,dp+1+n)<<endl;
	}
	return 0;
}
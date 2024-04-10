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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int dp[110][110][2];
int tot;
int dfs(int u,int v,int cnt)
{
	if(dp[u][v][cnt]>=0)
		return dp[u][v][cnt];
	if(!u&&!v)
		return cnt;
	int &res=dp[u][v][cnt];
	if((tot-u-v)%2)
	{
		res=0;
		if(u)
			res=max(res,dfs(u-1,v,cnt));
		if(v)
			res=max(res,dfs(u,v-1,cnt));
	}
	else
	{
		res=1;
		if(u)
			res=min(res,dfs(u-1,v,cnt));
		if(v)
			res=min(res,dfs(u,v-1,cnt^1));
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		int n;
		cin>>n;
		tot=n;
		int cnt[2]={0,0};
		while(n--)
		{
			int x;
			cin>>x;
			cnt[(x%2+2)%2]++;
		}
		if(dfs(cnt[0],cnt[1],0))
			puts("Bob");
		else	puts("Alice");
	}
	return 0;
}
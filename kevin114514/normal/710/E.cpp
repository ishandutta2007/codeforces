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
ll dp[10001000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,x,y;
	cin>>n>>x>>y;
	memset(dp,0x3f,sizeof(dp));
	dp[1]=x;
	for(int i=1;i<n;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+x);
		if(i*2+1<=n)
			dp[i*2+1]=min(dp[i*2+1],dp[i]+x+y);
		if(i*2-1<=n)
			dp[i*2-1]=min(dp[i*2-1],dp[i]+x+y);
		if(i*2<=n)
			dp[i*2]=min(dp[i*2],dp[i]+y);
	}
	cout<<dp[n]<<endl;
	return 0;
}
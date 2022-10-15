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
int dp[500100][2];
int v[500100];
const int mod=998244353;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n+10;i++)
			dp[i][0]=dp[i][1]=0;
//		vector<int> v;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",v+i);
		}
//		srt(v);
		dp[0][0]=1;
		for(int i=0;i<n;i++)
		{
			int x=v[i];
			if(x)
			{
				dp[x-1][1]=(dp[x-1][1]+dp[x-1][1])%mod;
				dp[x-1][1]=(dp[x-1][1]+dp[x-1][0])%mod;
			}
			dp[x+1][0]=(dp[x+1][0]+dp[x+1][0])%mod;
			dp[x+1][1]=(dp[x+1][1]+dp[x+1][1])%mod;
			dp[x+1][0]=(dp[x+1][0]+dp[x][0])%mod;
//			dp[x+2][0]=(dp[x+2][0]+dp[x][1])%mod;
		}
		for(int i=0;i<=n+1;i++)
		{
			ans=(ans+dp[i][0])%mod;
			ans=(ans+dp[i][1])%mod;
//			cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		printf("%d\n",(ans+mod-1)%mod);
	}
	return 0;
}
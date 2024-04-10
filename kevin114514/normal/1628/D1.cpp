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
void die(string S){puts(S.c_str());exit(0);}
const ll mod=1000000007;
ll dp[2020][2020];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=0;
		for(int i=m;i<=n;i++)
			dp[i][m]=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(i+m-j==n)
					dp[i][j]=1ll*k*(m-j)%mod;
		for(int i=n-1;i>=0;i--)
			for(int j=m;j>=0&&i+m-j<n;j--)
			{
//				cout<<i<<" "<<j<<" "<<dp[i+1][j+1]<<" "<<dp[i+1][j]<<endl;
				dp[i][j]=(dp[i+1][j+1]+dp[i+1][j])*((mod+1)/2)%mod;
			}
		cout<<dp[0][0]<<endl;
	}
	return 0;
}
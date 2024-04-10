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
int a[110];
int dp[110][110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				vector<int> v;
				for(int k=i;k<=j;k++)
					v.pb(a[k]);
				srt(v);
				v.resize(unique(ALL(v))-v.begin());
				int x=0;
				while(x<sz(v)&&v[x]==x) x++;
				dp[i][j]=x+1;
			}
		for(int len=1;len<=n;len++)
			for(int i=1;i<=n-len+1;i++)
			{
				int j=i+len-1;
				for(int k=i;k<j;k++)
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				ans+=dp[i][j];
		cout<<ans<<endl;
	}
	return 0;
}
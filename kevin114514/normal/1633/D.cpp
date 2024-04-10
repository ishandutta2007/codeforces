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
int dp[1010];
int f[1010][12010];
int b[1010],c[1010];
int main()
{
	memset(dp,inf,sizeof(dp));
	dp[1]=0;
	for(int i=1;i<1010;i++)
		for(int j=1;j<=i;j++)
			if(i+i/j<1010)
				dp[i+i/j]=min(dp[i+i/j],dp[i]+1);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		k=min(k,n*12);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				f[i][j]=0;
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++)
			cin>>c[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<=k;j++)
			{
				f[i+1][j]=max(f[i+1][j],f[i][j]);
				if(j+dp[b[i+1]]<=k)
					f[i+1][j+dp[b[i+1]]]=max(f[i+1][j+dp[b[i+1]]],f[i][j]+c[i+1]);
			}
		cout<<f[n][k]<<endl;
	}
	return 0;
}
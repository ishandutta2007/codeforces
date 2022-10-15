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
void die(string S){puts(S.c_str());exit(0);}
int a[5050];
bool f[5050][5050];
int dp[5050];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		a[n+1]=0;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				f[i][j]=0;
		for(int i=0;i<=n;i++)
			f[i+1][i]=1;
		for(int len=2;len<=n;len+=2)
			for(int i=1,j=len;j<=n;i++,j++)
			{
				if(a[i]!=a[i+1])
					f[i][j]|=f[i+2][j];
				if(a[i]!=a[j])
					f[i][j]|=f[i+1][j-1];
				if(a[j]!=a[j-1])
					f[i][j]|=f[i][j-2];
			}
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<=n;i++) if(dp[i]>=0)
			for(int j=i+1;j<=n+1;j+=2) if(!i||j>n||a[i]==a[j]) if(f[i+1][j-1])
				dp[j]=max(dp[j],dp[i]+1);
		cout<<dp[n+1]-1<<endl;
	}
	return 0;
}
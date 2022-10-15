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
int dp[1001000];
int main()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		dp[x]=0;
	}
	int ans=0;
	for(int i=1000000;i>=1;i--) if(dp[i]==-1)
	{
		vector<int> v;
		for(int j=i+i;j<=1000000;j+=i)
			if(dp[j]==0)
				v.pb(j);
		srt(v);
		for(int j=0;j<sz(v)-1;j++)
			if(__gcd(v[j],v[j+1])==i)
				dp[i]=0;
		if(dp[i]==0)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
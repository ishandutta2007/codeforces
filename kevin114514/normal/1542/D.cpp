#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
ll x[550];
ll dp[550][550];
void upd(ll &a,ll b)
{
	a+=b;
	a%=998244353;
}
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++)
	{
		string S;
		cin>>S;
		if(S[0]=='+')
		{
			cin>>x[i];
			v.pb(mp(i,x[i]));
		}
		else	x[i]=-1;
	}
	ll ans=0;
	for(int i=0;i<sz(v);i++)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		int pos=v[i].first;
		int k=v[i].second;
		for(int j=0;j<pos;j++) for(int l=0;l<n;l++)
		{
			if(x[j]<0)
			{
				upd(dp[j+1][l],dp[j][l]);
				upd(dp[j+1][max(0,l-1)],dp[j][l]);
			}
			else
			{
				if(x[j]<=k)
				{
					upd(dp[j+1][l+1],dp[j][l]);
					upd(dp[j+1][l],dp[j][l]);
				}
				else	upd(dp[j+1][l],dp[j][l]*2);
			}
		}
		for(int l=0;l<n;l++)
			upd(dp[pos+1][l],dp[pos][l]);
		for(int j=pos+1;j<n;j++) for(int l=0;l<n;l++)
		{
			if(x[j]<0)
			{
				upd(dp[j+1][l],dp[j][l]);
				if(l)
					upd(dp[j+1][l-1],dp[j][l]);
			}
			else
			{
				if(x[j]<k)
				{
					upd(dp[j+1][l+1],dp[j][l]);
					upd(dp[j+1][l],dp[j][l]);
				}
				else	upd(dp[j+1][l],dp[j][l]*2);
			}
		}
		for(int l=0;l<n;l++)
			upd(ans,dp[n][l]*k);
	}
	cout<<ans<<endl;
	return 0;
}
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
ll v[200200];
ll dp[200200];
ll psum[200200];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i],psum[i]=psum[i-1]+v[i];
	for(int i=1;i<=n;i++)
		dp[i]=max(dp[i-1],(psum[i]+i-1)/i);
	for(int i=1;i<=n;i++)
		dp[i]=max(dp[i],(psum[n]+i-1)/i);
	reverse(dp+1,dp+n+1);
	int q;
	cin>>q;
	while(q--)
	{
		ll t;
		cin>>t;
		if((n+2-(upper_bound(dp,dp+n+1,t)-dp))<=n)
			cout<<(n+2-(upper_bound(dp,dp+n+1,t)-dp))<<endl;
		else	puts("-1");
	}
	return 0;
}
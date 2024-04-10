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
ll l[100100],r[100100],a[100100];
ll dp[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	ll k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i]>>a[i];
	memset(dp,inf,sizeof(dp));
	dp[0]=0;
	ll res=1ll*inf*inf;
	for(int i=0;i<=n;i++)
	{
		ll tot=dp[i]+1;
		if(tot>=1ll*inf*inf+1)
			continue;
		ll sum=k;
		for(int j=i+1;j<=n+1;j++)
		{
			if(j==n+1)
			{
				res=min(res,tot*k-sum);
				break;
			}
			ll need=max(0ll,(a[j]-sum+k-1)/k);
			if(need>r[j]-l[j]) break;
			tot+=need;
			sum+=need*k;
			sum-=a[j];
			if(need<r[j]-l[j]||j==n||r[j]<l[j+1])
				dp[j]=min(dp[j],tot);
		}
	}
	if(res==1ll*inf*inf)
		die("-1");
	cout<<res<<endl;
	return 0;
}
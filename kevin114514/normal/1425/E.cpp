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
ll a[114514],d[114514];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>d[i];
	if(k==0)
	{
		ll ans=0;
		ll sum=0;
		for(int i=n;i>=1;i--)
		{
			sum+=a[i];
			ans=max(ans,sum-d[i]);
		}
		cout<<ans<<endl;
	}
	else if(k==1)
	{
		ll ans=0;
		ll sum=0;
		for(int i=1;i<n;i++)
		{
			sum+=a[i];
			ans=max(ans,sum-d[i]);
		}
		sum=0;
		for(int i=n;i>=2;i--)
		{
			sum+=a[i];
			ans=max(ans,sum-d[i]);
		}
		sum+=a[1];
		sum-=*min_element(a+2,a+n+1);
		sum-=d[1];
		ans=max(ans,sum);
		sum=0;
		for(int i=1;i<n;i++)
			sum+=a[i];
		sum-=*min_element(d+1,d+n);
		ans=max(ans,sum);
		sum=0;
		for(int i=1;i<=n;i++)
			sum+=a[i];
		for(int i=1;i<n;i++)
			ans=max(ans,sum-d[i]-d[i+1]);
		cout<<ans<<endl;
	}
	else
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=a[i];
		ans-=*min_element(d+1,d+n);
		ans=max(ans,0ll);
		ans=max(ans,a[n]-d[n]);
		cout<<ans<<endl;
	}
	return 0;
}
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
int a[1010];
const int thres=100000;
int n,k;
const ll mod=998244353;
int dp[1010][1010];
int psum[1010][1010];
ll calc(int x)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=psum[i][j]=0;
	dp[0][1]=1;
	psum[0][1]=1;
	for(int i=1;i<n;i++)
	{
		int p=upper_bound(a,a+n,a[i]-x)-a-1;
		for(int j=1;j<=k;j++)
			if(j==1)
				dp[i][j]=1;
			else if(p>=0)
				dp[i][j]=psum[p][j-1];
			else	dp[i][j]=0;
		for(int j=1;j<=k;j++)
			psum[i][j]=(psum[i-1][j]+dp[i][j])%mod;
	}
	ll ans=0;
	for(int i=0;i<n;i++)
		ans=(ans+dp[i][k])%mod;
	return ans;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ll ans=0;
	for(int i=1;i<=thres/(k-1);i++)
	{
		ll x=calc(i);
		ans+=x;
	}
	cout<<ans%mod<<endl;
	return 0;
}
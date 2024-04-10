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
ll a[100100];
ll dp[100100];
int main()
{
	for(int i=0;i<100100;i++)
		dp[i]=-1ll*inf*inf;
	dp[0]=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=0;j--)
			dp[j+1]=max(dp[j+1],dp[j]+(j+1)*a[i]);
	printf("%lld\n",(*max_element(dp,dp+n+1)));
	return 0;
}
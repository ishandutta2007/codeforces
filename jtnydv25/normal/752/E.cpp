#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int N = 1e7+10;
int dp[N],a[N];
int main()
{
	int n,k;
	sd(n),sd(k);
	rep(i,1,n+1) sd(a[i]);
	int lo = 0, hi = 10000000;
	// cout<<lo<<" "<<hi<<endl;
	while(lo < hi)
	{
		// cout<<lo<<" "<<hi<<endl;
		int mid =(lo+hi+1)>>1;
		memset(dp,0,sizeof dp);
		int up = min(mid<<1,N);
		rep(i,mid,up) dp[i] = 1;
		if((mid<<1)<=10000000)
		rep(i,mid<<1,10000001) dp[i] = dp[i>>1] +dp[i-(i>>1)];
		ll ans = 0;
		rep(i,1,n+1) ans+=dp[a[i]];
		if(ans >=k) lo = mid;
		else hi = mid-1;
	}
	cout<<(lo==0?-1:lo)<<endl;
}
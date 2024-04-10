#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e6+100;
const ll inf=1e17;
ll n,r1,r2,r3,d, dp0[maxn],dp1[maxn],dp2[maxn],a[maxn],f[maxn],ans;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>r1>>r2>>r3>>d;
  dp1[0] = dp2[0] = inf;
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      ll dm1 =  min(a[i]*r1+r1, r2) + r1;
      dp0[i+1] = min(dp0[i],min(dp1[i],dp2[i])) + a[i]*r1+r3 +d;
      dp1[i+1] = min(dp0[i],min(dp1[i],dp2[i])) + dm1 + 3*d;
      dp2[i+1] = min( dp1[i] + dm1 + d , dp2[i] + dm1 + 3*d);
      //  dp[i+1]=dp[i] + min( a[i]*r1+r3, min( a[i]*r1+r1, r2) +2d+r1) +d;
    }
  ans=min(dp0[n],min(dp1[n], dp2[n]))-d;
  f[n-1] = min(a[n-1]*r1+r3, min(r2, a[n-1]*r1+r1) + r1 + 2*d);
  for(int i=n-2;i>=0;i--)
    {
      f[i] = f[i+1] + 2*d + min(a[i]*r1+r3, min(r2, a[i]*r1+r1) + r1);
      ans = min(ans, f[i] + min(dp0[i],min(dp1[i],dp2[i])));
    }
  cout<<ans<<endl;
}
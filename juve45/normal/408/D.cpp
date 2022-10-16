#include <iostream>
#define MOD 1000000007
using namespace std;

long long n, dp[1008], p[1008];

int main()
{
cin>>n;

for(int i=1;i<=n;i++)
    cin>>p[i];

dp[1]=1;

for(int i=2;i<=n+1;i++)
{
  dp[i] = ( (dp[i-1] + 1) * 2 - dp[p[i-1]] ) % MOD; 
  if(dp[i] < 0)
    dp[i] += MOD;
//  cout << dp[i] <<' ' << i << ' ' << p[i-1] << '\n';
}
int ans = dp[n+1] - 1;
if(ans < 0) ans += MOD;
cout << ans << '\n';
    return 0;
}
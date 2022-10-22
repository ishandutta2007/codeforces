#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5000009];
int fr[5000009];
int dv[5000009];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,x,mx=0;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>x;
        fr[x]++;
        mx=max(mx,x);
    }
    for(int i=mx;i>=1;i--)
        for(int j=i;j<=mx;j+=i)dv[i]+=fr[j];
   dp[1]=n;
   ll ans=n;
   for(int i=1;i<=mx;i++)
   for(int j=2*i;j<=mx;j+=i)
       dp[j]=max(dp[j],dp[i]+dv[j]*1LL*(j-i));
   for(int i=1;i<=mx;i++)ans=max(ans,dp[i]);
   cout<<ans;

	return 0;
}
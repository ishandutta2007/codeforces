#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,p,k;
pair<ll,ll> a[100009];
ll s[100009][8];
ll dp[100002][130];
ll go(ll x,ll bl)
{
    if(x<0)return 0;

    ll y=a[x].second;
    if(dp[y][bl]!=-1)return dp[y][bl];
    int u=0;
    for(int i=0;i<p;i++)
        if(!(bl&(1<<i)))dp[y][bl]=max(dp[y][bl],s[y][i]+go(x-1,(bl|(1<<i))));else u++;
  if(n-1-x-u<k)dp[y][bl]=max(dp[y][bl],a[x].first+go(x-1,bl));
 else if(u<=p)  dp[y][bl]=max(dp[y][bl],go(x-1,bl));
  return dp[y][bl];
}
int main()
{
    ios::sync_with_stdio(0);
//cin>>n>>p>>k;
  scanf("%I64d%I64d%I64d",&n,&p,&k);
  memset(dp,-1,sizeof dp);
  for(int i=0;i<n;i++){
        scanf("%I64d",&a[i].first);
        //cin>>a[i].first;
  a[i].second=i;}
  sort(a,a+n);
  for(int i=0;i<n;i++)
    for(int j=0;j<p;j++)scanf("%I64d",&s[i][j]);
        //cin>>s[i][j];
printf("%I64d",go(n-1,0));
  //cout<<go(n-1,0);

    return 0;
}
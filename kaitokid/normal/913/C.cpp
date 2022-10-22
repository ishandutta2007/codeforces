#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,c[33],pw[33],l,res;
ll ans= 2e18;
int main()
{
    ios::sync_with_stdio(0);

    cin>>n>>l;

   cin>>c[0];
   pw[0]=1;
   for(int i=1;i<n;i++){cin>>c[i];pw[i]=2*pw[i-1];c[i]=min(c[i],2*c[i-1]);}
 for(int i=n-1;i>=0;i--)
 {
  res+=(l/pw[i])*c[i];
  l%=pw[i];
  if(l==0){ans=min(res,ans);break;}
  ans=min(ans,res+c[i]);

 }
 cout<<ans;
    return 0;
}
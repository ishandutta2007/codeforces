#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009],n;
int go(int x)
{
    if(x==n-1)return 1;
    int ans=2;
    int u=x+1;
    ll s=2*a[u]-a[x];
    int ff=lower_bound(a+u+1,a+n,s)-a;
    while(ff<n)
    {
        ans++;
        u=ff;
        s=2*a[u]-a[x];
        ff=lower_bound(a+u+1,a+n,s)-a;

    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
      cin>>n;
      for(int i=0;i<n;i++)cin>>a[i];
      int ans=0;
      for(int i=0;i<n;i++)
      {
          if(i>0 && a[i]==a[i-1])continue;
          ans=max(ans,go(i));
      }
      cout<<n-ans<<endl;
    }
    return 0;
}
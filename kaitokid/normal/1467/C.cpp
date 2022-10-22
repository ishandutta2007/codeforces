#include <bits/stdc++.h>

using namespace std;
int mod=1e9+7;
typedef long long ll;
int main()

{
    ll r=1e9+10;
    ll n[3],sm[3]={0,0,0};
    ll mn[3]={r,r,r};
    cin>>n[0]>>n[1]>>n[2];
    for(int i=0;i<3;i++)
    {
        ll x;
        for(int j=0;j<n[i];j++){cin>>x;sm[i]+=x;mn[i]=min(mn[i],x);}
    }
    ll s=sm[0]+sm[1]+sm[2];
    ll ans=s-2*min(sm[0],min(sm[1],sm[2]));
    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
        ans=max(ans,s-2*(mn[i]+mn[j]));
    cout<<ans;

      return 0;
}
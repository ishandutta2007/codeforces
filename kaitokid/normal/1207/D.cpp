#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=998244353;
ll c1[300009],c2[300009],ans1=1,ans2=1,ans3=1,ans=1,x,y,n;
pair<ll,ll> a[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {ans=(ans*(i+1))%mod;
        cin>>a[i].first>>a[i].second;
        c1[a[i].first]++;
        c2[a[i].second]++;
        ans1=(ans1*c1[a[i].first])%mod;
        ans2=(ans2*c2[a[i].second])%mod;
    }
    ans=(ans-ans1-ans2+2*mod)%mod;
    sort(a,a+n);
    bool bl=true;
    int d=1;
    for(int i=1;i<n;i++)
    {
        if(a[i].second<a[i-1].second){bl=false;break;}
        if(a[i]==a[i-1])d++;else d=1;
        ans3=(ans3*d)%mod;
    }
    if(bl)ans=(ans+ans3)%mod;
    cout<<ans;
    return 0;
}
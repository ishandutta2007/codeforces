#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[300005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ll sum=0,ans=0,d;
    for(int i=1;i<=n;i++)
    {
        d=min(ans,a[i]/2);
        sum+=d;
        ans-=d;
        a[i]-=2*d;
        sum+=a[i]/3;
        ans+=a[i]%3;
    }
    cout<<sum<<endl;
}
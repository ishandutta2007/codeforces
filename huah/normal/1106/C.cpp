#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[300005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int l=1,r=n;
    ll ans=0;
    while(l<r)
    {
        ans+=(a[l]+a[r])*(a[l]+a[r]);
        l++;r--;
    }
    cout<<ans;
}
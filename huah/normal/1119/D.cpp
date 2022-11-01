#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
ll a[100005],b[100005],c[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
        b[i]=a[i+1]-a[i];
    sort(b+1,b+n);
    for(int i=1;i<n;i++)
        c[i]=c[i-1]+b[i];
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        ll t=lower_bound(b+1,b+n,r-l+1)-b;
        if(t==n||b[t]>r-l+1) t--;
        ll ans=(r-l+1)*(n-t)+c[t];
        printf("%lld ",ans);
    }
}
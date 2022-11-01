#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--) b[i]=__gcd(a[i],b[i+1]);
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans=__gcd(ans,a[i]*b[i+1]/__gcd(a[i],b[i+1]));
    printf("%lld\n",ans);
}
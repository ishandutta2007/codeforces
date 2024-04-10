#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[5],b[5];

int main()
{
    scanf("%lld%lld",&n,&m);
    a[0] = n/5; b[0] = m/5;
    for(ll i=1;i<5;i++) {
        a[i] = n/5 + (n%5>=i);
        b[i] = m/5 + (m%5>=i);
    }
    ll ans = 0;
    ans += a[0]*b[0];
    for(ll i=1;i<5;i++) ans += a[i]*b[5-i];
    printf("%lld",ans);
}
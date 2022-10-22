#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    cin>>a>>b;
    ll c=a+b;
    ll ba=0,bb=0;
    ll ans=0x3f3f3f3f3f3f3f3f3f;
    for(ll i=1;i*i<=c;i++){
        if(a%i==0)ba=i;
        if(b%i==0)bb=i;
        if(c%i)continue;
        ll j=c/i;
        if(j>=a/ba||j>=b/bb)ans=min(ans,(i+j)*2);
    }
    printf("%lld",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main()
{
    scanf("%lld",&n);
    if(!n) {puts("1"); return 0;}
    ll prev = 0, ans = 0;
    ll x = n*n;
    for(ll i=-n;i<=n;i++) {
        ll cur = ((ll)sqrt(x-i*i))*2+1;
        ans += max(abs(prev-cur)-2,0ll) + 2;
        prev = cur;
    }
    printf("%lld",ans-2);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005];

int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll cur = 1;
    for(ll i=1;i<=n;i++) {
        if(a[i]>=cur) {
            cur++;
        }
    }
    printf("%lld",cur);
}
#include<bits/stdc++.h>
typedef long long ll;
ll n,h,k,rem,cnt;

int main()
{
    scanf("%lld%lld%lld",&n,&h,&k);
    for(ll i=0;i<n;i++) {
        ll cur;
        scanf("%lld",&cur);
        if(rem+cur>h) {
            rem = 0;
            cnt++;
        }
        rem += cur;
        cnt += rem/k;
        rem %=k;
    }
    if(rem) cnt++;
    printf("%lld",cnt);
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000005],cnt[1111111],ans;

int main() {
    ll i,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        cnt[a[i]]++;
    }
    for(i=0;i<1111111;i++) {
        cnt[i+1]+=cnt[i]/2;
        cnt[i]%=2;
    }
    for(i=0;i<1111111;i++) {
        ans+=cnt[i];
    }
    printf("%lld",ans);
}
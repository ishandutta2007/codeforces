#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,a[100005],cnt[100005],pal;
ll lc[100005], rc[100005], lb, rb;

int main()
{
    ll i, odd = 0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        cnt[a[i]]++;
    }
    for(i=1;i<=n;i++) odd += cnt[i]%2;
    if(odd>1) {
        puts("0");
        return 0;
    }
    for(i=1;i<=n/2;i++) {
        if(a[i]!=a[n+1-i]) break;
        pal = i;
    }
    if(pal==n/2) {
        printf("%lld\n",n*(n+1)/2);
        return 0;
    }
    for(i=1;i<=n/2;i++) {
        lc[a[i]]++;
        if(lc[a[i]]*2>cnt[a[i]]) break;
    }
    if(i>n/2 && (n%2==0 || lc[a[i]]*2+1<=cnt[a[i]])) {
        for(;i<=n;i++) {
            if(a[i]!=a[n+1-i]) break;
        }
    }
    lb = i;
    reverse(a+1,a+1+n);
    for(i=1;i<=n/2;i++) {
        rc[a[i]]++;
        if(rc[a[i]]*2>cnt[a[i]]) break;
    }
    if(i>n/2 && (n%2==0 || rc[a[i]]*2+1<=cnt[a[i]])) {
        for(;i<=n;i++) {
            if(a[i]!=a[n+1-i]) break;
        }
    }
    rb = i;
    reverse(a+1,a+1+n); pal++;
    printf("%lld",(lb+rb-pal)*pal);
}
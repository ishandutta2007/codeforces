#include<bits/stdc++.h>
#define MAX   100100
typedef long long ll;
ll a[MAX];
int n;
ll max(const ll &x,const ll &y) {
    if (x>y) return (x); else return (y);
}
void init(void) {
    scanf("%d",&n);
    int i;
    ll maxv=-1LL;
    ll s=0LL;
    for (i=1;i<=n;i=i+1) {
        scanf("%I64d",&a[i]);
        maxv=max(maxv,a[i]);
        s=s+a[i];
    }
    if (s%(n-1)!=0) printf("%I64d",max(maxv,s/(n-1)+1LL));
    else printf("%I64d",max(maxv,s/(n-1)));
}
int main(void) {
    init();
    return 0;
}
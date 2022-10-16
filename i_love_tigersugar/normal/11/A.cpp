#include<bits/stdc++.h>
#define MAX   2020
typedef long long ll;
ll a[MAX];
ll d;
int n;
ll req(const ll &a,const ll &b) {
    if ((b-a)%d==0) return ((b-a)/d);
    else return ((b-a)/d+1);
}
void process(void) {
    int i;
    ll s=0LL;
    ll t;
    scanf("%d",&n);
    scanf("%I64d",&d);
    for (i=1;i<=n;i=i+1) scanf("%I64d",&a[i]);
    for (i=2;i<=n;i=i+1) {
        if (a[i]>a[i-1]) continue;
        t=req(a[i],a[i-1]+1);
        s=s+t;
        a[i]=a[i]+t*d;
    }
    printf("%I64d",s);
}
int main(void) {
    process();
    return 0;
}
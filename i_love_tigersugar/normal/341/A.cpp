#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
typedef long long ll;
ll n;
ll a[MAX];
ll s;
ll gcd(ll x,ll y) { 
    while (true) {
        if (x==0LL) return (y);
        if (y==0LL) return (x);
        if (x%y==0LL) return (y);
        if (y%x==0LL) return (x);
        if (x>y) x=x%y; else y=y%x;     
    }
}
void init(void) {
    scanf("%I64d",&n);
    ll i;
    for (i=1;i<=n;i=i+1) scanf("%I64d",&a[i]);
    sort(&a[1],&a[n+1]);
    s=0LL;
    for (i=1;i<=n;i=i+1) s+=a[i]*(4*i-1-2*n);   
    ll t=gcd(s,n);
    printf("%I64d %I64d",s/t,n/t);
}
int main(void) {
    init();
    return 0;
}
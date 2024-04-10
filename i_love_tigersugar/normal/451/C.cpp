#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
typedef long long ll;
bool solve(ll k,ll y,ll z,ll &x1,ll &x2,ll &x3) {
    if ((k-y-2*z)%3!=0) return (false);
    x3=(k-y-2*z)/3;
    x2=x3+z;
    x1=x2+y;
    return (x1>=0 && x2>=0 && x3>=0);
}
bool canwin(ll n,ll x1,ll x2,ll x3) {
    if (n%3!=0) return (false);
    ll t=n/3;
    if (x1>t) return (false);
    if (x2>t) return (false);
    if (x3>t) return (false);
    return (true);
}
bool test(void) {
    ll n,k,d1,d2;
    scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
    ll x1,x2,x3;
    REP(i1,2) REP(i2,2)
        if (solve(k,i1?d1:-d1,i2?d2:-d2,x1,x2,x3) && canwin(n,x1,x2,x3)) return (true);
    return (false);
}
int main(void) {
    int t;
    scanf("%d",&t);
    REP(zz,t) if (test()) printf("yes\n"); else printf("no\n");
    return 0;
}
#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
typedef long long ll;
int m,n;
ll k;
inline bool ok(ll x) {
    ll tmp=0;
    FOR(i,1,m) {
        tmp+=min(1LL*n,x/i);
        if (tmp>=k) return (true);
    }
    return (false);
}
void process(void) {
    cin>>m>>n>>k;
    ll l=0;
    ll r=1LL*m*n;
    while (true) {
        if (l==r) {
            cout<<l;
            return;
        }
        if (r-l==1) {
            if (ok(l)) cout<<l; else cout<<r;
            return;
        }
        ll m=(l+r)>>1;
        if (ok(m)) r=m; else l=m+1;
    }
}
int main(void) {
    process();
    return 0;
}
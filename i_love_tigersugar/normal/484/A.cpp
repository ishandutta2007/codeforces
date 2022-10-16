#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
typedef long long ll;
ll answer(ll l,ll r) {
    if (l==r) return (l);
    ll res=0;
    FORD(i,60,0) {
        if (BIT(l,i)==BIT(r,i)) {
            if (BIT(l,i)) res|=MASK(i);
        } else {
            ll tmp=(MASK(i+1)-1)&r;
            if (tmp==MASK(i+1)-1) return (res|(MASK(i+1)-1));
            else return (res|(MASK(i)-1));
        }
    }
}
int main(void) {
    int t;
    cin>>t;
    REP(zz,t) {
        ll l,r;
        cin>>l>>r;
        cout<<answer(l,r)<<"\n";
    }
    return 0;
}
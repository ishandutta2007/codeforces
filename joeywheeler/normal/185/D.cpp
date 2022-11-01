#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll add(ll a, ll b, ll p) {
    return (p+(a+b)%p)%p;
}

ll mul(ll a, ll b, ll p) {
    return (a*b)%p;
}

ll pw(ll a, ll b, ll p) {
    ll r = 1;
    while (b) {
        if (b&1) r = mul(r,a,p);
        a = mul(a,a,p);
        b /= 2;
    }
    return r;
}

ll ppw(ll a, ll b, ll c, ll p) {
    if (a%p == 0) return 0;
    return pw(a, pw(b,c,p-1), p);
}

int main() {
    int t; scanf("%d", &t);
    FO(Z,0,t) {
        ll x, l, r, p; scanf("%lld %lld %lld %lld", &x, &l, &r, &p);
        if (p == 2) {
            printf("%lld\n", (x+1)%2);
            continue;
        }
        bool odd = x%2;
        x = ppw(x,2,l,p); r -= l;
        ll m;
        if (x == 0) {
            m = 1;
        } else if (x == 1) {
            m = pw(2,r+1,p);
        } else {
            m = mul(add(ppw(x,2,r+1,p),-1,p),pw(x-1,p-2,p),p);
        }
        if (odd) m = mul(m, pw(pw(2,r,p),p-2,p), p);
        printf("%lld\n", m);
    }
}
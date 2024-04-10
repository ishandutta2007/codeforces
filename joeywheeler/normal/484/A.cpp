#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int popcount(ll x) {
    int r = 0;
    while (x) {
        r++; x -= x&-x;
    }
    return r;
}

ll solve(ll l, ll r) {
    ll res = r;
    FO(i,0,63) {
        if (r & (1ll<<i)) {
            ll tmp = r ^ (1ll<<i);
            tmp |= (1ll<<i)-1;
            if (tmp >= l && popcount(tmp) >= popcount(res)) res = tmp;
        }
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    FO(_,0,n) {
        ll l, r; scanf("%lld %lld", &l, &r);
        printf("%lld\n", solve(l,r));
    }
}
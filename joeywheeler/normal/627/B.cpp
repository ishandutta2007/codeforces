#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;

struct rt {
    ll v[400005];
    ll mxv;

    void add(int i, ll c) {
        i += n;
        v[i] = min(v[i]+c,mxv);
        for (; i>1; i/=2) v[i/2] = v[i]+v[i^1];
    }

    ll qu(int l, int r) {
        ll a = 0;
        for (l+=n,r+=n; l < r;l /= 2, r/=2) {
            if (l&1) a += v[l++];
            if (r&1) a += v[--r];
        }
        return a;
    }
} ra, rb;

int k; ll a, b; int q;

int main() {
    scanf("%d %d %lld %lld %d", &n, &k, &a, &b, &q);
    ra.mxv = b;
    rb.mxv = a;
    FO(z,0,q) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int d, v; scanf("%d%d", &d, &v); d--;
            ra.add(d,v);
            rb.add(d,v);
        } else {
            int p; scanf("%d", &p); p--; // [p,p+k) is repair
            ll ans = ra.qu(0,p) + rb.qu(p+k,n);
            printf("%lld\n", ans);
        }
    }
}
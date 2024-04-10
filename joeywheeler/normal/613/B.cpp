#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct st {
    int v, ind;
};

bool cmp1(st a, st b) {
    return a.v < b.v;
}

bool cmp2(st a, st b) {
    return a.ind < b.ind;
}

int n, a, cf, cm;
ll m;
st s[100005];
ll ss[100005];

ll n2mk(int f, int x) {
    // raise first f to at least x
    st tmp; tmp.v = x; tmp.ind = -1;
    int i = lower_bound(s,s+f,tmp,cmp1)-s;
    return 1ll * x * i - ss[i];
}

int bb8;

int cmin(int f, ll r) {
    // first f, using r
    int s = 0, e = a, b = 0;
    while (s <= e) {
        int md = (s+e)/2;
        if (n2mk(f,md) <= r) {
            b = md;
            s = md+1;
        } else {
            e = md-1;
        }
    }
    bb8 = b;
    return b;
}

int main() {
    scanf("%d%d%d%d%lld", &n, &a, &cf, &cm, &m);
    FO(i,0,n) scanf("%d", &s[i].v), s[i].ind = i;
    sort(s,s+n,cmp1);
    FO(i,0,n) {
        ss[i+1] = ss[i] + s[i].v;
    }
    ll om = m;
    ll res = 0;
    int rat = 0;
    FO(i,0,n+1) {
        int mn = cmin(n-i, m);
        ll nr = 1ll *  mn * cm + 1ll * i * cf;
        if (nr > res) {
            res = nr;
            rat = i;
        }
        if (i == n) break;
        m -= a - s[n-i-1].v;
        if (m < 0) break;
    }
    printf("%lld\n", res);
    m = om;
    FO(i,0,n+1) {
        if (i == rat) break;
        m -= a-s[n-i-1].v;
    }
    cmin(n-rat,m);
    FO(i,0,n-rat) {
        s[i].v = max(bb8,s[i].v);
    }
    FO(i,0,rat) {
        s[n-i-1].v = a;
    }
    sort(s,s+n,cmp2);
    FO(i,0,n) printf("%d%c", s[i].v, " \n"[i+1==n]);
}
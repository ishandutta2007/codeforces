#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct thing {
    ll dv;
    int f, s;
    int t;

    bool operator<(const thing &o) {
        return dv < o.dv;
    }
};

struct swp {
    ll dv;
    int f[2], s[2];
};

swp mks(thing a, thing b) {
    swp r; r.dv = a.dv + b.dv;
    r.f[a.t] = a.f;
    r.s[a.t] = a.s;
    r.f[b.t] = b.f;
    r.s[b.t] = b.s;
    return r;
}

int n; ll a[2005];
int m; ll b[2005];
ll x = 0, y = 0;

bool better(swp s, swp t) {
    return abs(s.dv+y-x) < abs(t.dv+y-x);
}

swp best;
vector<thing> sa, sb;

void go() {
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    for (thing t : sa) {
        // t.dv + dv2 ~ x-y
        // dv2 ~ x-y-t.dv
        thing tmp; tmp.dv = x-y-t.dv;
        int i = lower_bound(sb.begin(), sb.end(), tmp)-sb.begin();
        for (int j = i-2; j <= i+2; j++) if (0 <= j && j < sz(sb)) {
            swp tms = mks(t, sb[j]);
            if (better(tms,best)) best = tms;
        }
    }
}

int main() {
    scanf("%d", &n); FO(i,0,n) scanf("%lld", a+i), a[i] *= 2;
    scanf("%d", &m); FO(i,0,m) scanf("%lld", b+i), b[i] *= 2;
    FO(i,0,n) x += a[i];
    y = x;
    FO(i,0,m) x += b[i];
    x /= 2;
    // want Sa as close to x as possible
    // want y+dv as close to x
    // dv close to x-y
    
    best.dv = 0;
    best.f[0] = best.f[1] = -1;
    best.s[0] = best.s[1] = -1;

    FO(i,0,n) {
        thing t; t.dv = -a[i];
        t.t = 0; t.f = i; t.s = -1;
        sa.push_back(t);
    }
    FO(i,0,m) {
        thing t; t.dv = b[i];
        t.t = 1; t.f = i; t.s = -1;
        sb.push_back(t);
    }
    go();
    sa.clear(); sb.clear();
    FO(i,0,n) FO(j,0,i) {
        thing t; t.dv = -a[i]-a[j];
        t.t = 0; t.f = i; t.s = j;
        sa.push_back(t);
    }
    FO(i,0,m) FO(j,0,i) {
        thing t; t.dv = b[i]+b[j];
        t.t = 1; t.f = i; t.s = j;
        sb.push_back(t);
    }
    go();
    x *= 2;
    y += best.dv;
    printf("%lld\n", abs((x-y)-y)/2);
    int k = 0;
    if (best.f[0] != -1) k++;
    if (best.s[0] != -1) k++;
    printf("%d\n", k);
    if (best.f[0] != -1) {
        printf("%d %d\n", 1+best.f[0], 1+best.f[1]);
        swap(a[best.f[0]],b[best.f[1]]);
    }
    if (best.s[0] != -1) {
        printf("%d %d\n", 1+best.s[0], 1+best.s[1]);
        swap(a[best.s[0]],b[best.s[1]]);
    }
    //FO(i,0,n) printf("%lld ", a[i]/2);
    //printf("\n");
    //FO(i,0,m) printf("%lld ", b[i]/2);
    //printf("\n");
}
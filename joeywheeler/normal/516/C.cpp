#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define N 300005
#define INF ll(1e16)

using namespace std;

typedef long long ll;

struct RT {
    pair<ll,int> v[4*N];

    pair<ll,int> q(int i, int rs, int re, int qs, int qe) {
        if (rs==re) return make_pair(-INF,-1);
        if (rs==qs && re==qe) {
            return v[i];
        } else {
            int md = (rs+re)/2;
            pair<ll,int> res(-INF,-1);
            if (qs < md) res = max(res, q(2*i+1, rs, md, qs, min(qe,md)));
            if (qe > md) res = max(res, q(2*i+2, md, re, max(qs,md), qe));
            return res;
        }
    }

    void u(int i, int rs, int re, int qi, ll qv) {
        if (rs+1 == re) v[i] = make_pair(qv,rs);
        else {
            int md = (rs+re)/2;
            if (qi < md) u(2*i+1, rs, md, qi, qv);
            if (qi >= md) u(2*i+2, md, re, qi, qv);
            v[i] = max(v[2*i+1], v[2*i+2]);
        }
    }

    ll qbut(int n, int qs, int qe, int qbut) {
        return max(q(0, 0, n, qs, qbut), q(0, 0, n, qbut+1, qe)).first;
    }
} rta, rtb;

int n, m;
ll d[N], p[N], h[N];
int a[N], b[N];

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) scanf("%lld", d+i);
    FO(i,0,n) scanf("%lld", h+i);
    FO(i,0,m) scanf("%d %d", a+i, b+i), a[i]--;
    FO(i,0,2*n) {
        p[i+1] = p[i] + d[i%n];
    }
    FO(i,0,2*n) {
        rta.u(0, 0, 2*n, i, 2*h[i%n] + p[i]);
        rtb.u(0, 0, 2*n, i, 2*h[i%n] - p[i]);
    }
    FO(i,0,m) {
        int len = b[i]-a[i];
        if (len <= 0) len += n;
        int l = a[i]+len, r = a[i]+n;
        pair<ll,int> A = rta.q(0, 0, 2*n, l, r);
        pair<ll,int> B = rtb.q(0, 0, 2*n, l, r);
        ll R = -INF;
        if (A.second != B.second) {
            R = A.first+B.first;
        } else {
            ll R0 = -INF, R1 = -INF;
            R0 = A.first + rtb.qbut(2*n, l, r, A.second);
            R1 = B.first + rta.qbut(2*n, l, r, B.second);
            R = max(R0,R1);
        }
        printf("%lld\n", R);
    }
}
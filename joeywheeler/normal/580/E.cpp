#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll MOD[2] = {1000000009ll, 1000000007ll};
ll BASE = 137;

struct hsh {
    ll val[2];
    int len;
};

ll pw[2][400005];

hsh rt[400005];
int as[400005];

hsh ohsh[10][400005];

hsh mrge(hsh a, hsh b) {
    FO(i,0,2) {
        a.val[i] = (a.val[i]*pw[i][b.len]+b.val[i])%MOD[i];
    }
    a.len += b.len;
    return a;
}

hsh q(int i, int rs, int re, int qs, int qe) {
    if (as[i] != -1) {
        return ohsh[as[i]][qe-qs];
    }
    if (rs == qs && re == qe) {
        return rt[i];
    } else {
        int md = (rs+re)/2;
        hsh res;
        memset(&res,0,sizeof(res));
        if (qs<md) res = mrge(res, q(2*i+1, rs, md, qs, min(qe,md)));
        if (qe>md) res = mrge(res, q(2*i+2, md, re, max(qs,md), qe));
        return res;
    }
}

void laz(int i, int rs, int re) {
    rt[i] = ohsh[as[i]][re-rs];
}

void u(int i, int rs, int re, int qs, int qe, int qv) {
    if (rs == qs && re == qe) {
        as[i] = qv;
        laz(i,rs,re);
    } else {
        int md = (rs+re)/2;
        if (as[i] != -1) {
            as[2*i+1] = as[2*i+2] = as[i];
            laz(2*i+1,rs,md);
            laz(2*i+2,md,re);
            as[i] = -1;
        }
        if (qs<md) u(2*i+1, rs, md, qs, min(qe,md), qv);
        if (qe>md) u(2*i+2, md, re, max(qs,md), qe, qv);
        rt[i] = mrge(rt[2*i+1],rt[2*i+2]);
    }
}

int n, m, k;

int main() {
    FO(j,0,2) {
        pw[j][0] = 1;
        FO(i,1,400005) pw[j][i] = (pw[j][i-1]*BASE)%MOD[j];
    }

    FO(i,0,10) {
        FO(j,0,2) {
            ohsh[i][1].val[j] = i+1;
        }
        ohsh[i][1].len = 1;
        FO(j,2,400005) ohsh[i][j] = mrge(ohsh[i][j-1],ohsh[i][1]);
    }

    memset(as,-1,sizeof as);
    scanf("%d%d%d", &n, &m, &k);
    FO(i,0,n) {
        char ch; scanf(" %c", &ch);
        int v = ch - '0';
        u(0,0,n,i,i+1,v);
    }
    FO(z,0,m+k) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r, c; scanf("%d%d%d", &l, &r, &c); l--;
            u(0,0,n,l,r,c);
        } else {
            int l, r, d; scanf("%d%d%d", &l, &r, &d); l--;
            hsh v1, v2;
            if (d == r-l) goto yes;
            v1 = q(0,0,n,l,r-d);
            v2 = q(0,0,n,l+d,r);
            if (memcmp(&v1, &v2, sizeof(v1)) == 0) goto yes;
            printf("NO\n");
            continue;
yes:
            printf("YES\n");
        }
    }
}
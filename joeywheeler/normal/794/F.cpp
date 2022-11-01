#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct vls {
    ll vl[10];

    vls() {
        FO(i,0,10) vl[i] = 0;
    }
};

struct prm {
    int to[10];

    prm() {
        FO(i,0,10) to[i] = i;
    }
};

vls applyv(vls a, prm b) {
    vls res;
    FO(i,0,10) {
        res.vl[b.to[i]] += a.vl[i];
    }
    return res;
}

// a applied first, then b
prm applyp(prm a, prm b) {
    prm rs;
    FO(i,0,10) {
        rs.to[i] = b.to[a.to[i]];
    }
    return rs;
}

vls rt[400005];
prm drt[400005];
ll iv[100005];

vls add(vls a, vls b) {
    vls res;
    FO(i,0,10) res.vl[i] = a.vl[i] + b.vl[i];
    return res;
}

void sv(int i, int rs, int re) {
    if (rs+1 == re) {
        ll p10 = 1;
        FO(j,0,12) {
            if (iv[rs]/p10) {
                rt[i].vl[(iv[rs]/p10)%10] += p10;
            }
            p10 *= 10;
        }
    } else {
        int md = (rs+re)/2;
        sv(2*i+1, rs, md);
        sv(2*i+2, md, re);
        rt[i] = add(rt[2*i+1], rt[2*i+2]);
    }
}

void push(int i, int rs, int re) {
    if (rs+1 != re) {
        rt[2*i+1] = applyv(rt[2*i+1], drt[i]);
        rt[2*i+2] = applyv(rt[2*i+2], drt[i]);
        drt[2*i+1] = applyp(drt[2*i+1], drt[i]);
        drt[2*i+2] = applyp(drt[2*i+2], drt[i]);
    }
    FO(j,0,10) drt[i].to[j] = j;
}

void upd(int i, int rs, int re, int qs, int qe, int x, int y) {
    push(i,rs,re);
    if (rs == qs && re == qe) {
        drt[i].to[x] = y;
        rt[i] = applyv(rt[i], drt[i]);
    } else {
        int md = (rs+re)/2;
        if (qs < md) upd(2*i+1, rs, md, qs, min(qe,md), x, y);
        if (qe > md) upd(2*i+2, md, re, max(qs,md), qe, x, y);
        rt[i] = add(rt[2*i+1], rt[2*i+2]);
    }
}

vls qu(int i, int rs, int re, int qs, int qe) {
    push(i, rs, re);
    if (rs == qs && re == qe) {
        return rt[i];
    } else {
        int md = (rs+re)/2;
        vls res;
        if (qs < md) res = add(res, qu(2*i+1, rs, md, qs, min(qe,md)));
        if (qe > md) res = add(res, qu(2*i+2, md, re, max(qs,md), qe));
        res = applyv(res, drt[i]);
        return res;
    }
}

int n, q;

int main() {
    scanf("%d %d", &n, &q);
    FO(i,0,n) scanf("%lld", iv+i);
    sv(0, 0, n);
    FO(_,0,q) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r, x, y; scanf("%d %d %d %d", &l, &r, &x, &y); l--;
            upd(0, 0, n, l, r, x, y);
        } else {
            int l, r; scanf("%d %d", &l, &r); l--;
            vls v = qu(0, 0, n, l, r);
            ll res = 0;
            FO(i,0,10) {
                res += v.vl[i] * i;
            }
            printf("%lld\n", res);
        }
    }
}
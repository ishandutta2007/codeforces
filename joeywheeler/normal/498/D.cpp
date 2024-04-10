#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct thing {
    // if i'm here ate i mod 60 how long to get to other end
    int t[60];
};

thing base(int p) {
    thing r;
    FO(i,0,60) {
        if (i % p == 0) r.t[i] = 2;
        else r.t[i] = 1;
    }
    return r;
}
thing bases[10];

thing mthing(const thing &a, const thing &b) {
    thing r;
    FO(i,0,60) {
        r.t[i] = a.t[i] + b.t[(i+a.t[i])%60];
    }
    return r;
}

thing rtree[400000];
int per[400000];

void init(int i, int rs, int re) {
    if (rs+1 == re) rtree[i] = bases[per[rs]];
    else {
        int md = (rs+re)/2;
        init(2*i+1, rs, md);
        init(2*i+2, md, re);
        rtree[i] = mthing(rtree[2*i+1], rtree[2*i+2]);
    }
}

void update(int i, int rs, int re, int qi) {
    if (rs+1 == re) rtree[i] = bases[per[qi]];
    else {
        int md = (rs+re)/2;
        if (qi < md) update(2*i+1, rs, md, qi);
        else update(2*i+2, md, re, qi);
        rtree[i] = mthing(rtree[2*i+1], rtree[2*i+2]);
    }
}

int query(int i, int rs, int re, int qs, int qe, int t) {
    if (rs == qs && re == qe) {
        return t + rtree[i].t[t%60];
    } else {
        int md = (rs+re)/2;
        if (qs < md) t = query(2*i+1, rs, md, qs, min(qe,md), t);
        if (qe > md) t = query(2*i+2, md, re, max(qs,md), qe, t);
        return t;
    }
}

int main() {
    FO(i,2,10) bases[i] = base(i);
    int n; scanf("%d", &n);
    FO(i,0,n) scanf("%d", &per[i]);
    init(0,0,n);

    int q; scanf("%d", &q);
    FO(_,0,q) {
        char ch; scanf(" %c", &ch);
        if (ch == 'C') {
            int i, p; scanf("%d %d", &i, &p); i--;
            per[i] = p;
            update(0, 0, n, i);
        } else {
            int x, y; scanf("%d %d", &x, &y); x--; y--;
            printf("%d\n", query(0, 0, n, x, y, 0));
        }
    }
}
#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;
const int N = 100005;

struct RT {
    int rt[4*N];
    int d[4*N];

    // find last <= v
    int fl(int i, int rs, int re, int v) {
        if (rt[i] > v) return -1;
        else if (rs+1 == re) return rs;
        else {
            int md = (rs+re)/2;
            v -= d[i];
            int res = fl(2*i+2, md, re, v);
            if (res != -1) return res;
            return fl(2*i+1, rs, md, v);
        }
    }

    // call with i = 0, [rs,re) = [0,n) (range of rtree), [qs,qe) is query, returns min
    int q(int i, int rs, int re, int qs, int qe) {
        if (rs == qs && re == qe) {
            return rt[i];
        } else {
            int md = (rs+re)/2;
            int res = 2e9;
            if (qs<md) res = min(res, q(2*i+1, rs, md, qs, min(qe,md)));
            if (qe>md) res = min(res, q(2*i+2, md, re, max(qs,md), qe));
            return res + d[i];
        }
    }

    // call with i = 0, [rs,re) = [0,n) (range of rtree), [qs,qe) is upd range, adds dv
    void u(int i, int rs, int re, int qs, int qe, int dv) {
        if (rs == qs && re == qe) {
            rt[i] += dv;
            d[i] += dv;
        } else {
            int md = (rs+re)/2;
            if (qs<md) u(2*i+1, rs, md, qs, min(qe,md), dv);
            if (qe>md) u(2*i+2, md, re, max(qs,md), qe, dv);
            rt[i] = d[i] + min(rt[2*i+1], rt[2*i+2]);
        }
    }
} rt;

int m;
int xv[100005];

int main() {
    scanf("%d", &m);
    FO(i,0,m) {
        int p, t;
        scanf("%d %d", &p, &t);
        p--;
        if (t == 1) {
            scanf("%d", &xv[p]);
            rt.u(0, 0, m, 0, p+1, -1);
        } else {
            rt.u(0, 0, m, 0, p+1, 1);
        }

        int j = rt.fl(0, 0, m, -1);
        if (j == -1) printf("%d\n", -1);
        else printf("%d\n", xv[j]);
    }
}
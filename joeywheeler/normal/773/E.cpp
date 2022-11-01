#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define INF 1000000000

using namespace std;

struct RT {
    const static int N = 500005;
    int rt[4*N];
    int d[4*N];

    void prp(int i, int rs, int re) {
        if (rs+1 != re) {
            rt[2*i+1] += d[i];
            d[2*i+1] += d[i];
            rt[2*i+2] += d[i];
            d[2*i+2] += d[i];
        }
        d[i] = 0;
    }

    int q(int i, int rs, int re, int qs, int qe) {
        prp(i, rs, re);
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

    void u(int i, int rs, int re, int qs, int qe, int dv) {
        prp(i, rs, re);
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
} rtm;

struct RT2 {
    const static int N = 500005;
    int rt[4*N];
    int d[4*N];

    void prp(int i, int rs, int re) {
        if (rs+1 != re) {
            rt[2*i+1] += d[i];
            d[2*i+1] += d[i];
            rt[2*i+2] += d[i];
            d[2*i+2] += d[i];
        }
        d[i] = 0;
    }

    // find first >= 0
    int q(int i, int rs, int re) {
        prp(i, rs, re);
        if (rt[i] < 0) return -1;
        //printf("Q [%d,%d): %d\n", rs, re, rt[i]);
        if (rs+1 == re) {
            return rs;
        } else {
            int md = (rs+re)/2;
            int res = -1;
            res = q(2*i+1, rs, md);
            if (res != -1) return res;
            res = q(2*i+2, md, re);
            return res;
        }
    }

    void u(int i, int rs, int re, int qs, int qe, int dv) {
        prp(i, rs, re);
        if (rs == qs && re == qe) {
            //printf("UP [%d,%d): %d\n", rs, re, dv);
            rt[i] += dv;
            d[i] += dv;
        } else {
            int md = (rs+re)/2;
            if (qs<md) u(2*i+1, rs, md, qs, min(qe,md), dv);
            if (qe>md) u(2*i+2, md, re, max(qs,md), qe, dv);
            rt[i] = d[i] + max(rt[2*i+1], rt[2*i+2]);
        }
    }
} rtf;

int n;
int a[500005];
pair<int,int> b[500005];
int p[500005];

int nl[500005];

int q(int i) {
    int r = 0;
    for (i++; i; i -= i&-i) r += nl[i];
    return r;
}

void u(int i, int v) {
    for (i++; i < 500005; i += i&-i) nl[i] += v;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    FO(i,0,n) b[i] = {a[i],i};
    sort(b,b+n);
    FO(i,0,n) p[b[i].second] = i;

    //FO(i,0,n) printf("%d ", p[i]);
    //printf("\n");

    rtf.u(0, 0, n+1, 0, n, -INF);
    rtm.u(0, 0, n, 0, n, INF);

    FO(i,0,n) {
        if (p[i]+1 != n) rtf.u(0, 0, n+1, p[i]+1, n, 1);
        rtf.u(0, 0, n+1, p[i], p[i]+1, INF+a[i]);
        if (p[i]+1 != n) rtm.u(0, 0, n, p[i]+1, n, -1);
        rtm.u(0, 0, n, p[i], p[i]+1, a[i]-INF);
        u(p[i], 1);

        int fng = rtf.q(0, 0, n+1);
        //printf("fng = %d\n", fng);
        assert(fng != -1);
        int res;
        if (fng == n) {
            res = -i-1;
        } else {
            res = i+rtm.q(0, 0, n, fng, n);
            res = min(res, i+1-2*q(fng-1));
        }
        printf("%d\n", res);
    }
}
#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define END 1001000000

using namespace std;

struct node {
    node *l, *r;
    int mx;

    node() {
        l = r = 0;
        mx = -1;
    }

    int qmax(int rs, int re, int qs, int qe) {
        if (qs == rs && qe == re) return mx;
        int md = (rs+re)/2;
        int res = -1;
        if (qs < md && l) res = max(res,l->qmax(rs, md, qs, min(qe,md)));
        if (qe > md && r) res = max(res,r->qmax(md, re, max(qs,md), qe));
        return res;
    };

    void set(int rs, int re, int qi, int v) {
        if (rs+1 == re) {
            mx = v;
        } else {
            if (!l) {
                l = new node;
                r = new node;
            }
            int md = (rs+re)/2;
            if (qi < md) l->set(rs, md, qi, v);
            else r->set(md, re, qi, v);

            mx = max(l->mx, r->mx);
        }
    }
};

node *root = new node;

int p[200005], l[200005];
int r[200005];
int n;

int nxt[18][200005];
int req[18][200005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d %d", &p[i], &l[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        int v = root->qmax(0, END, p[i], min(p[i]+l[i]+1,END-10));
        v = max(v, p[i]+l[i]);
        r[i] = v;
        //printf("r[%d]=%d\n", i, v);
        root->set(0, END, p[i], v);
    }
    for (int i = 0; i < n; i++) {
        nxt[0][i] = upper_bound(p,p+n,r[i])-p;
        if (nxt[0][i] != n) req[0][i] = p[nxt[0][i]] - r[i];
        //printf("NXT,REQ[%d]=%d,%d\n", i, nxt[0][i], req[0][i]);
    }
    nxt[0][n] = n;

    FO(i,1,18) FO(j,0,n+1) {
        nxt[i][j] = nxt[i-1][nxt[i-1][j]];
        req[i][j] = req[i-1][j] + req[i-1][nxt[i-1][j]];
    }

    int q; scanf("%d", &q);
    FO(z,0,q) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        int res = 0;
        for (int i = 17; i >= 0; i--) if (nxt[i][a] <= b) {
            //printf("%d to %d\n", a, nxt[i][a]);
            res += req[i][a];
            a = nxt[i][a];
        }
        printf("%d\n", res);
    }
}
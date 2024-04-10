#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000003
#define MC  800010

using namespace std;

int add(int a, int b) {
    a += b; if (a >= MOD) a -= MOD;
    return a;
}

typedef pair<int,int> T;

T I = make_pair(0, 0);
struct nd {
    T v;
    nd *l, *r;

    nd() {
        v = I;
        l = r = 0;
    }
};

T op(const T &a, const T &b) {
    if (a.first == b.first) return make_pair(a.first, add(a.second,b.second));
    else return max(a,b);
}

T q(nd *i, int rs, int re, int qs, int qe) {
    if (qs == qe) return I;
    if (i == 0) return I;
    if (rs==qs && re==qe) return i->v;
    else {
        int md=(rs+re)/2;
        T r = I;
        if (qs<md) r = op(r, q(i->l, rs, md, qs, min(qe,md)));
        if (qe>md) r = op(r, q(i->r, md, re, max(qs,md), qe));
        return r;
    }
}

nd *u(nd *i, int rs, int re, int qi, T qv) {
    nd *res = i;
    if (rs+1==re) res->v = op(res->v,qv);
    else {
        if (i->l == 0) {
            i->l = new nd; i->r = new nd;
        }
        int md=(rs+re)/2;
        if (qi<md) res->l = u(i->l, rs, md, qi, qv);
        else res->r = u(i->r, md, re, qi, qv);
        res->v = op(res->l->v, res->r->v);
    }
    return res;
}

int n, Q;
int h[400005];

nd *l[400005];
nd *r[400005];
T nl[400005];
int nw[400005];

int qa[400005];
int qb[400005];
int ans[400005];

int cc[800010], C;

vector<pair<int,int> > ql[400005]; // val to q, where to put ans
vector<pair<int,int> > qr[400005]; // val to q, where to put ans

void stmc() {
    scanf("%d %d", &n, &Q);
    FO(i,0,n) {
        scanf("%d ", h+i);
        cc[C++] = h[i];
    }
    FO(i,0,Q) {
        scanf("%d %d", qa+i, qb+i); qa[i]--;
        cc[C++] = qb[i];
    }
    sort(cc,cc+C);
    C = unique(cc,cc+C)-cc;
    FO(i,0,n) h[i] = lower_bound(cc,cc+C,h[i])-cc;
    FO(i,0,Q) qb[i] = lower_bound(cc,cc+C,qb[i])-cc;
}

void lpc(int i) {
    for (auto p : ql[i]) {
        ans[p.second] += q(l[i], 0, MC, 0, p.first).first;
    }
}

void rpc(int i) {
    for (auto p : qr[i]) {
        ans[p.second] += q(r[i], 0, MC, p.first+1, MC).first;
    }
}

int main() {
    stmc();
    FO(z,0,Q) {
        int a = qa[z], b = qb[z];

        ql[a].push_back(make_pair(b, z));
        qr[n-a-1].push_back(make_pair(b, z));
    }

    T bl = I;
    l[0] = new nd;
    lpc(0);

    FO(i,0,n) {
        T t = q(l[i], 0, MC, 0, h[i]);
        t.first++;
        t = op(t, make_pair(1,1));
        //printf("l: %d: %d,%d\n", i, t.first, t.second);

        bl = op(bl, t);

        nl[i] = t;
        l[i+1] = u(l[i], 0, MC, h[i], t);
        lpc(i+1);
    }
    r[0] = new nd;
    rpc(0);
    FO(i,0,n) {
        T t = q(r[i], 0, MC, h[n-1-i]+1, MC);
        t.first++;
        t = op(t, make_pair(1,1));
        //printf("r: %d: %d,%d\n", n-1-i, t.first, t.second);

        if (nl[n-i-1].first + t.first - 1 == bl.first) {
            nw[n-1-i] = nl[n-1-i].second * 1ll * t.second % MOD;
            //printf("%d on best, nw = %d\n", n-1-i, nw[n-1-i]);
        } else {
            nw[n-1-i] = -1;
        }
        //if (nw[n-1-i] == bl.second) printf("ALLBEST: %d\n", n-1-i);

        r[i+1] = u(r[i], 0, MC, h[n-1-i], t);
        rpc(i+1);
    }

    FO(z,0,Q) {
        int a = qa[z], b = qb[z];

        int bwo = -1;
        if (nw[a] != bl.second) bwo = bl.first;
        else bwo = bl.first-1;

        int bw = ans[z] + 1;

        printf("%d\n", max(bwo,bw));
    }
}
#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct ks {
    int h[4001];

    ks() {
        memset(h,0,sizeof h);
    }

    void add(int c, int H) {
        for (int i = 4000; i >= c; i--) h[i] = max(h[i], h[i-c]+H);
    }
};

int qmerge(const ks &a, const ks &b, int c) {
    int res = 0;
    for (int i = 0; i <= c; i++) res = max(res, a.h[i]+b.h[c-i]);
    return res;
}

struct qu {
    int t;
    int b;
    int i;

    bool operator<(const qu &o) const {
        return t < o.t;
    }
};

struct item {
    int c, h, t;
    bool operator<(const item &o) const {
        return t < o.t;
    }
};

int n, p;
item l[4005];
multiset<qu> queries;
int ans[20005];

void solve(int ls, int le) {
    if (ls >= le) return;


    int md = (ls+le)/2;

    //printf("[%d,%d) - [%d,%d]\n", ls, le, l[md].t, l[md].t+p-1);

    vector<ks> L; vector<int> lt;
    vector<ks> R; vector<int> rt;
    L.reserve(md-ls+1);
    lt.reserve(md-ls+1);
    for (int i = md; i >= ls; i--) {
        if (l[i].t+p-1 >= l[md].t) {
            lt.push_back(l[i].t+p-1);
            if (L.empty()) L.push_back(ks());
            else L.push_back(L.back());
            L.back().add(l[i].c, l[i].h);
        }
    }
    R.reserve(le-md); rt.reserve(le-md);
    R.push_back(ks()); rt.push_back(0);
    for (int i = md+1; i < le; i++) {
        if (l[md].t+p-1 >= l[i].t) {
            rt.push_back(l[i].t);
            R.push_back(R.back());
            R.back().add(l[i].c, l[i].h);
        }
    }
    qu fq; fq.t = l[md].t;
    set<qu>::iterator it = queries.lower_bound(fq);
    while (it != queries.end()) {
        //printf("PROCESS? %d\n", it->i);
        if (it->t > l[md].t+p-1) break;
        //printf("PROCESS %d\n", it->i);
        int lp = 0;
        for (int i = 0; i < sz(lt) && lt[i] >= it->t; i++) lp = i;
        int rp = 0;
        for (int i = 0; i < sz(rt) && rt[i] <= it->t; i++) rp = i;
        ans[it->i] = qmerge(L[lp], R[rp], it->b);
        queries.erase(it);
        it = queries.lower_bound(fq);
    }

    solve(ls, md);
    solve(md+1, le);
}

int main() {
    scanf("%d%d", &n, &p);
    FO(i,0,n) {
        scanf("%d%d%d", &l[i].c, &l[i].h, &l[i].t);
    }
    sort(l,l+n);
    int q; scanf("%d", &q);
    FO(i,0,q) {
        qu q;
        scanf("%d%d", &q.t, &q.b); q.i = i;
        queries.insert(q);
    }
    solve(0,n);

    FO(i,0,q) printf("%d\n", ans[i]);
}
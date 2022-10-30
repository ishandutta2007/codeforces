#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define P 10000019ll
#define Q 1000000007ll

using namespace std;

int n, k;

struct dp {
    int v[1005];

    dp() {
        FO(i,0,k+1) v[i] = 0;
    }

    void add(pair<int,int> l) {
        int x = l.first, w = l.second;
        for (int i = k; i >= w; i--) v[i] = max(v[i], v[i-w]+x);
    }
};

int del[50005];
pair<int,int> ins[50005];
pair<int,int> pt[50005];
int t[50005];
int ind[50005];
int r[50005];

struct rt {
    vector<pair<int,int> > v[50000*4];

    void u(int i, int rs, int re, int qs, int qe, pair<int,int> p) {
        if (rs==qs && re==qe) v[i].push_back(p);
        else {
            int md=(rs+re)/2;
            if (qs<md) u(2*i+1, rs, md, qs, min(qe,md), p);
            if (qe>md) u(2*i+2, md, re, max(qs,md), qe, p);
        }
    }

    void g(int i, int rs, int re, dp f) {
        for (auto p : v[i]) f.add(p);
        if (rs+1 == re) {
            long long ans = 0;
            long long cp = 1;
            FO(j,1,k+1) {
                ans += cp * f.v[j];
                cp = (cp * P) % Q;
                ans %= Q;
            }
            r[rs] = ans;
        } else {
            int md=(rs+re)/2;
            g(2*i+1, rs, md, f);
            g(2*i+2, md, re, f);
        }
    }
};

rt a;

int main() {
    scanf("%d%d", &n, &k);
    FO(i,0,n) {
        scanf("%d%d", &ins[i].first, &ins[i].second);
    }
    int q; scanf("%d", &q);
    FO(i,0,50005) del[i] = q;
    int cind = n;
    FO(i,0,q) {
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            scanf("%d%d", &pt[i].first, &pt[i].second);
            ind[i] = ++cind;
        } else if (t[i] == 2) {
            int x; scanf("%d", &x);
            del[x] = i+1;
        }
    }
    FO(i,0,n) {
        a.u(0, 0, q, 0, del[i+1], ins[i]);
    }
    FO(i,0,q) if (t[i] == 1) {
        a.u(0, 0, q, i, del[ind[i]], pt[i]);
    }
    a.g(0,0,q,dp());
    FO(i,0,q) if (t[i] == 3) printf("%d\n", r[i]);
}
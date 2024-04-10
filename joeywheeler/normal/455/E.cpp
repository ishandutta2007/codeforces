#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

typedef pair<ll,ll> ii;
#define m first
#define b second
#define X second.first
#define Y second.second

ll is(ii i, ii j) {
    return (i.b-j.b) / (j.m-i.m);
}

ll e(ii i, ll x) {
    return i.m * x + i.b;
}

struct CH {
    vector<ii> s;
    int c;

    CH() : c(0) {}

    void add(ii l) {
        while (sz(s) >= 2 && is(s.back(), l) < is(s.back(), *(s.end()-2))) s.pop_back();
        s.push_back(l);
    }

    ll q(ll x) {
        while (c+1 < sz(s) && e(s[c+1],x) <= e(s[c],x)) c++;
        return e(s[c],x);
    }
};

ll v[100005];
ll c[100005];
CH rtree[400005];
int n, m;

void init(int I, int rs, int re) {
    if (rs+1 == re) {
        rtree[I].add(ii(v[rs], v[rs]*rs-c[rs]));
    } else {
        int md = (rs+re)/2;
        init(2*I+1, rs, md);
        init(2*I+2, md, re);

        vector<ii> &l = rtree[2*I+1].s, &r = rtree[2*I+2].s;
        CH &x = rtree[I];
        int i = 0, j = 0;
        while (i < sz(l) || j < sz(r)) {
            if (i == sz(l)) x.add(r[j++]);
            else if (j == sz(r)) x.add(l[i++]);
            else if (l[i].m > r[j].m) x.add(l[i++]);
            else if (l[i].m < r[j].m) x.add(r[j++]);
            else {
                if (l[i].b < r[j].b) x.add(l[i]);
                else x.add(r[j]);
                i++; j++;
            }
        }
    }
}

bool qc(pair<ii,ii> a, pair<ii,ii> b) {
    return a.X-a.Y < b.X-b.Y;
}

ll res;

void rq(int i, int rs, int re, int qs, int qe, ll x) {
    if (rs == qs && re == qe) {
        res = min(res, rtree[i].q(x));
    } else {
        int md = (rs+re)/2;
        if (qs < md) rq(2*i+1, rs, md, qs, min(qe,md), x);
        if (qe > md) rq(2*i+2, md, re, max(qs,md), qe, x);
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", &v[i]);
    FO(i,0,n) c[i+1] = c[i]+v[i];
    init(0,0,n);
    scanf("%d", &m);
    vector<pair<ii,ii> > q(m);
    FO(i,0,m) {
        q[i].first.first = i;
        scanf("%lld %lld", &q[i].X, &q[i].Y);
    }
    sort(q.begin(), q.end(), qc);
    FO(i,0,sz(q)) {
        res = 1e18;
        rq(0,0,n,q[i].Y-q[i].X,q[i].Y,q[i].X-q[i].Y);
        res += c[q[i].Y];
        q[i].first.second = res;
    }
    sort(q.begin(), q.end());
    FO(i,0,sz(q)) printf("%lld\n", q[i].first.second);
}
#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct thng {
    int prefp, prefm;
    int sufp, sufm;
    int bst;
    int len;
};

thng pls() {
    thng t;
    t.prefp = 1; t.prefm = 0;
    t.sufp = 1; t.sufm = 1;
    t.bst = 1;
    t.len = 1;
    return t;
}

thng mns() {
    thng t;
    t.prefp = 1; t.prefm = 1;
    t.sufp = 0; t.sufm = 1;
    t.bst = 1;
    t.len = 1;
    return t;
}

thng zer() {
    thng t;
    t.prefp = 0; t.prefm = 0;
    t.sufp = 0; t.sufm = 0;
    t.bst = 0;
    t.len = 1;
    return t;
}

thng mrg(thng a, thng b) {
    thng res;

    res.prefp = a.prefp;
    if (a.sufp == a.len && a.prefp != 0) res.prefp = max(res.prefp, a.len + b.prefp);
    if (a.sufm == a.len && a.prefp != 0) res.prefp = max(res.prefp, a.len + b.prefm);

    res.prefm = a.prefm;
    if (a.sufp == a.len && a.prefm != 0) res.prefm = max(res.prefm, a.len + b.prefp);
    if (a.sufm == a.len && a.prefm != 0) res.prefm = max(res.prefm, a.len + b.prefm);

    res.sufp = b.sufp;
    if (b.prefp == b.len && b.sufp != 0) res.sufp = max(res.sufp, b.len + a.sufp);
    if (b.prefm == b.len && b.sufp != 0) res.sufp = max(res.sufp, b.len + a.sufm);

    res.sufm = b.sufm;
    if (b.prefp == b.len && b.sufm != 0) res.sufm = max(res.sufm, b.len + a.sufp);
    if (b.prefm == b.len && b.sufm != 0) res.sufm = max(res.sufm, b.len + a.sufm);

    res.bst = max(a.bst, b.bst);
    res.bst = max(res.bst, a.sufp + b.prefp);
    res.bst = max(res.bst, a.sufm + b.prefm);

    res.len = a.len + b.len;

    return res;
}

struct RT {
    thng t[300005*4];

    void upd(int i, int rs, int re, int qi, int qt) {
        if (rs+1 == re) {
            t[i] = qt == -1 ? mns() : qt == 1 ? pls() : zer();
        } else {
            int md = (rs+re)/2;
            if (qi < md) upd(2*i+1, rs, md, qi, qt);
            else upd(2*i+2, md, re, qi, qt);
            t[i] = mrg(t[2*i+1], t[2*i+2]);
        }
    }
};

typedef long long ll;

ll dlt[300005];
ll a[300005];
int n, m;

RT rt;

int sgn(ll x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%lld", a+i);
    FO(i,0,n-1) {
        dlt[i] = a[i+1]-a[i];
        rt.upd(0, 0, n-1, i, sgn(dlt[i]));
    }
    scanf("%d", &m);
    FO(z,0,m) {
        int l, r; ll d; scanf("%d %d %lld", &l, &r, &d);
        l--;
        if (l) {
            dlt[l-1] += d;
            rt.upd(0, 0, n-1, l-1, sgn(dlt[l-1]));
        }
        if (r != n) {
            dlt[r-1] -= d;
            rt.upd(0, 0, n-1, r-1, sgn(dlt[r-1]));
        }
        printf("%d\n", rt.t[0].bst+1);
    }
}
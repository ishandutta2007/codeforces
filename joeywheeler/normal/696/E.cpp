#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

tuple<ll,int,int> inft(1e18,1e9,-1);

struct RT {
    set<tuple<ll, int, int> > *lf;
    tuple<ll, int, int> *v;
    ll *lu;
    int n;

    void init(int _n) {
        n = _n;
        v = new tuple<ll, int, int>[4*n];
        lu = new ll[4*n];
        lf = new set<tuple<ll, int, int> >[n];
        FO(i,0,4*n) {
            lu[i] = 0;
            v[i] = inft;
        }
        FO(i,0,n) {
            lf[i].insert(inft);
        }
    }

    void ins(int i, int rs, int re, int qi, tuple<ll, int, int> p) {
        if (rs+1 == re) {
            lf[qi].insert(p);
            v[i] = *lf[qi].begin();
        } else {
            int md = (rs+re)/2;
            if (qi < md) ins(2*i+1, rs, md, qi, p);
            else ins(2*i+2, md, re, qi, p);
            v[i] = min(v[2*i+1], v[2*i+2]);
            get<0>(v[i]) += lu[i];
        }
    }

    void rem(int i, int rs, int re, int qi, tuple<ll, int, int> p) {
        get<0>(p) -= lu[i];
        if (rs+1 == re) {
            lf[qi].erase(p);
            v[i] = *lf[qi].begin();
            get<0>(v[i]) += lu[i];
        } else {
            int md = (rs+re)/2;
            if (qi < md) rem(2*i+1, rs, md, qi, p);
            else rem(2*i+2, md, re, qi, p);
            v[i] = min(v[2*i+1], v[2*i+2]);
            get<0>(v[i]) += lu[i];
        }
    }

    tuple<ll,int,int> gmn(int i, int rs, int re, int qs, int qe) {
        tuple<ll,int,int> res = inft;
        if (rs == qs && re == qe) res = v[i];
        else {
            int md = (rs+re)/2;
            if (qs < md) {
                auto p = gmn(2*i+1, rs, md, qs, min(qe,md));
                get<0>(p) += lu[i];
                res = min(res, p);
            }
            if (qe > md) {
                auto p = gmn(2*i+2, md, re, max(qs,md), qe);
                get<0>(p) += lu[i];
                res = min(res, p);
            }
        }
        return res;
    }

    void add(int i, int rs, int re, int qs, int qe, ll k) {
        if (rs == qs && re == qe) {
            get<0>(v[i]) += k;
            lu[i] += k;
        } else {
            int md = (rs+re)/2;
            if (qs < md) add(2*i+1, rs, md, qs, min(qe,md), k);
            if (qe > md) add(2*i+2, md, re, max(qs,md), qe, k);
            v[i] = min(v[2*i+1], v[2*i+2]);
            get<0>(v[i]) += lu[i];
        }
    }
};

int n, m, q;
vector<int> u[100005];
int ss[100005];
int hc[100005];
int tl[100005];
int hd[100005];
int dp[100005];
int pr[100005];
RT rt[100005];
ll rtdw[200005];
int le[100005], re[100005], T;

void go(int i, int p) {
    le[i] = T++;
    pr[i] = p;
    dp[i] = dp[p]+1;
    ss[i] = 1;
    int hw = -1, hj = -1;
    for (int j : u[i]) if (j != p) {
        go(j, i);
        ss[i] += ss[j];
        if (ss[j] > hw) {
            hw = ss[j];
            hj = j;
        }
    }

    if (hj == -1) {
        tl[i] = i;
        hd[i] = i;
    } else {
        tl[i] = tl[hj];
        hd[tl[i]] = i;
    }

    re[i] = T;
}

int gi(int i) {
    return dp[i] - dp[hd[i]];
}

int gs(int i) {
    return gi(tl[i])+1;
}

ll qdw(int i) {
    ll r = 0;
    for (i += T; i > 0; i /= 2) {
        r += rtdw[i];
    }
    return r;
}

tuple<ll,int,int> getg(int x, int y) {
    tuple<ll,int,int> res(1e18,1e9,-1);
    while (hd[x] != hd[y]) {
        if (dp[hd[x]] < dp[hd[y]]) swap(x,y);
        auto p = rt[hd[x]].gmn(0,0,gs(x),0,gi(x)+1);
        if (hd[x] != 1) get<0>(p) += qdw(le[pr[hd[x]]]);
        res = min(res, p);
        x = pr[hd[x]];
    }
    if (dp[x] > dp[y]) swap(x,y);
    auto p = rt[hd[x]].gmn(0,0,gs(x),gi(x),gi(y)+1);
    if (hd[x] != 1) get<0>(p) += qdw(le[pr[hd[x]]]);
    res = min(res, p);

    return res;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    FO(i,0,n-1) {
        int x, y; scanf("%d %d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    go(1,0);
    FO(i,1,n+1) {
        hd[i] = hd[tl[i]];
    }

    FO(i,1,n+1) {
        //printf("hd,tl,dp,gi[%d] = %d, %d, %d, %d\n", i, hd[i], tl[i], dp[i], gi(i));
        if (hd[i] == i) {
            rt[i].init(gi(tl[i])+1);
        }
    }
    FO(i,1,m+1) {
        int c; scanf("%d", &c);
        rt[hd[c]].ins(0,0,gs(c),gi(c),make_tuple(i, c, i));
    }
    FO(z,0,q) {
        int t; scanf("%d", &t);
        //printf("z=%d\n", z);
        if (t == 1) {
            int x, y, k; scanf("%d %d %d", &x, &y, &k);
            vector<int> tkn;
            while (k) {
                auto bg = getg(x,y);
                ll w; int c, i;
                tie(w,c,i) = bg;
                if (i == -1) break;

                //printf("TAKE %d\n", i);
                tkn.push_back(i);
                if (hd[c] != 1) get<0>(bg) -= qdw(le[pr[hd[c]]]);
                rt[hd[c]].rem(0,0,gs(c),gi(c),bg);
                k--;
            }
            printf("%d", sz(tkn));
            for (int x : tkn) printf(" %d", x);
            printf("\n");
        } else {
            int x; ll k; scanf("%d %lld", &x, &k);

            int l = le[x], r = re[x];
            for (l += T, r += T; l < r; l /= 2, r /= 2) {
                if (l&1) rtdw[l++] += k;
                if (r&1) rtdw[--r] += k;
            }

            rt[hd[x]].add(0,0,gs(x),gi(x),gs(x),k);
        }
    }
}
#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define N 200005

struct thing {
    int nt[10][10];
    char frst, last;

    thing(char c=0, int len=0) {
        frst = last = c;
        FO(i,0,10) FO(j,0,10) nt[i][j] = 0;
        if (c >= 'a') nt[c-'a'][c-'a'] = len-1;
    }
};

thing mrge(thing a, thing b) {
    thing res;
    FO(i,0,10) FO(j,0,10) res.nt[i][j] = a.nt[i][j] + b.nt[i][j];
    res.nt[a.last-'a'][b.frst-'a']++;
    res.frst = a.frst;
    res.last = b.last;
    return res;
}

struct RT {
    char dirty[4*N];
    thing t[4*N];

    void pushf(int i, int rs, int re) {
        if (dirty[i]) {
            if (rs+1 != re) {
                dirty[2*i+1] = dirty[i];
                dirty[2*i+2] = dirty[i];
                int md = (rs+re)/2;
                t[2*i+1] = thing(dirty[i], md-rs);
                t[2*i+2] = thing(dirty[i], re-md);
            }
            dirty[i] = 0;
        }
    }

    void upd(int i, int rs, int re, int qs, int qe, char c) {
        pushf(i, rs, re);
        if (rs == qs && re == qe) {
            dirty[i] = c;
            t[i] = thing(c, re-rs);
        } else {
            int md = (rs+re)/2;
            if (qs < md) upd(2*i+1, rs, md, qs, min(qe,md), c);
            if (qe > md) upd(2*i+2, md, re, max(qs,md), qe, c);
            t[i] = mrge(t[2*i+1], t[2*i+2]);
        }
    }

    void init(int i, int rs, int re, char *s) {
        if (rs+1 == re) {
            t[i] = thing(s[rs], 1);
        } else {
            int md = (rs+re)/2;
            init(2*i+1, rs, md, s);
            init(2*i+2, md, re, s);
            t[i] = mrge(t[2*i+1], t[2*i+2]);
        }
    }
} rt;

int n, m, k;
char is[200005];
char p[20];
int loc[20];


int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf(" %s", is);
    rt.init(0, 0, n, is);
    FO(z,0,m) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r; char c; scanf("%d%d %c", &l, &r, &c);
            l--;
            rt.upd(0, 0, n, l, r, c);
        } else {
            scanf(" %s", p);
            FO(i,0,k) loc[p[i]-'a'] = i;
            int res = 1;
            FO(i,0,k) FO(j,0,k) if (loc[i] >= loc[j]) res += rt.t[0].nt[i][j];
            printf("%d\n", res);
        }
    }
}
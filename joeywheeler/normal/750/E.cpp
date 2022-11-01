#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct tng {
    int nw[5][5];
};

tng mrg(tng a, tng b) {
    tng res;
    FO(i,0,5) FO(j,0,5) {
        res.nw[i][j] = 1e9;
        FO(k,0,5) res.nw[i][j] = min(res.nw[i][j], a.nw[i][k] + b.nw[k][j]);
    }
    return res;
}

tng gettng(char c) {
    tng res;
    FO(i,0,5) FO(j,0,5) res.nw[i][j] = 1e9;
    if (c == '2') {
        res.nw[0][1] = 0;
        res.nw[0][0] = 1;
        FO(i,0,5) if (i != 0) res.nw[i][i] = 0;
    } else if (c == '0') {
        res.nw[1][2] = 0;
        res.nw[1][1] = 1;
        FO(i,0,5) if (i != 1) res.nw[i][i] = 0;
    } else if (c == '1') {
        res.nw[2][3] = 0;
        res.nw[2][2] = 1;
        FO(i,0,5) if (i != 2) res.nw[i][i] = 0;
    } else if (c == '6') {
        res.nw[3][3] = 1;
        res.nw[4][4] = 1;
        FO(i,0,5) if (i != 3 && i != 4) res.nw[i][i] = 0;
    } else if (c == '7') {
        res.nw[3][4] = 0;
        res.nw[3][3] = 1;
        FO(i,0,5) if (i != 3) res.nw[i][i] = 0;
    } else {
        FO(i,0,5) res.nw[i][i] = 0;
    }
    return res;
}

tng ot[10];

int n, Q;
char s[200005];

tng rt[800005];

void init(int i, int rs, int re) {
    if (rs+1 == re) {
        rt[i] = ot[s[rs]-'0'];
    } else {
        int md = (rs+re)/2;
        init(2*i+1, rs, md);
        init(2*i+2, md, re);
        rt[i] = mrg(rt[2*i+1], rt[2*i+2]);
    }
    //printf("[%d,%d):\n", rs, re);
    //FO(k,0,5) FO(j,0,5) if (rt[i].nw[k][j] < 1e8) printf("%d->%d: %d\n", k, j, rt[i].nw[k][j]);
}

int nw[5];
int tp[5];

void q(int i, int rs, int re, int qs, int qe) {
    if (rs==qs && re==qe) {
        FO(j,0,5) tp[j] = 1e9;
        FO(j,0,5) FO(k,0,5) tp[k] = min(tp[k], nw[j] + rt[i].nw[j][k]);
        FO(j,0,5) nw[j] = tp[j];
    } else {
        int md = (rs+re)/2;
        if (qs<md) q(2*i+1, rs, md, qs, min(qe,md));
        if (qe>md) q(2*i+2, md, re, max(qs,md), qe);
    }
}

int main() {
    scanf("%d %d %s", &n, &Q, s);
    FO(i,0,10) ot[i] = gettng('0'+i);
    init(0, 0, n);
    FO(z,0,Q) {
        int l, r; scanf("%d %d", &l, &r);
        l--;
        nw[0] = 0;
        FO(i,1,5) nw[i] = 1e9;
        q(0, 0, n, l, r);
        int ans = nw[4];
        if (ans > 1e8) printf("-1\n");
        else printf("%d\n", ans);
    }
}
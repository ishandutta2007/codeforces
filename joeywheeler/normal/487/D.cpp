#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef pair<int,int> ii;
#define y first
#define x second

int n, m;

struct thingy {
    ii go[12];
    int sz;
};

thingy merge(thingy a, thingy b) {
    thingy res;
    res.sz = a.sz + b.sz;
    FO(i,0,m) {
        if (a.go[i].y == -1) {
            res.go[i] = b.go[a.go[i].x];
        } else if (a.go[i].y == -2) {
            res.go[i] = a.go[i];
        } else {
            res.go[i] = a.go[i];
            res.go[i].y += b.sz;
        }
    }
    return res;
}

thingy buildthingy(const char *s) {
    thingy res; res.sz = 1;
    int l=m+1,r=-1;
    FO(i,0,m) {
        if (s[i] == '<') res.go[i] = ii(0,-1);
        else {
            l = i;
            break;
        }
    }
    for (int i = m-1; i >= 0; i--) {
        if (s[i] == '>') res.go[i] = ii(0,m);
        else {
            r = i;
            break;
        }
    }
    int seen[12];
    FO(i,0,m) seen[i] = -1;
    FO(i,l,r+1) {
        int cur = i;
        if (seen[cur] != -1) continue;
        while (1) {
            if (seen[cur] == i) break;
            else if (seen[cur] != -1) break;
            seen[cur] = i;
            if (s[cur] == '^') break;
            if (s[cur] == '>') cur++;
            else cur--;
        }
        ii val;
        if (s[cur] == '^') val = ii(-1,cur);
        else if (seen[cur] == i) val = ii(-2,-2);
        else if (seen[cur] != -1) val = res.go[cur];
        cur = i;
        while (1) {
            if (seen[cur] != i) break;
            seen[cur] = -2;
            res.go[cur] = val;
            if (s[cur] == '>') cur++;
            else cur--;
        }
    }
    return res;
}

char g[120005][12];

thingy rt[4*120005];

void initrt(int i, int rs, int re) {
    if (rs+1 == re) {
        rt[i] = buildthingy(g[rs]);
    } else {
        int md = (rs+re)/2;
        initrt(2*i+1,rs,md);
        initrt(2*i+2,md,re);
        rt[i] = merge(rt[2*i+2],rt[2*i+1]);
    }
}

void rebuild(int i, int rs, int re, int qi) {
    if (rs+1 == re) {
        rt[i] = buildthingy(g[rs]);
    } else {
        int md = (rs+re)/2;
        if (qi < md) rebuild(2*i+1, rs, md, qi);
        if (qi >= md) rebuild(2*i+2, md, re, qi);
        rt[i] = merge(rt[2*i+2],rt[2*i+1]);
    }
}

thingy gthingy(int i, int rs, int re, int qs, int qe) {
    if (rs==qs && re == qe) return rt[i];
    else {
        int md=(rs+re)/2;
        thingy res;
        bool init=false;
        if (qs<md) {
            res = gthingy(2*i+1, rs, md, qs, min(qe,md));
            init = true;
        }
        if (qe > md) {
            if (init) res = merge(gthingy(2*i+2, md, re, max(qs,md), qe), res);
            else res = gthingy(2*i+2, md, re, max(qs,md), qe);
        }
        return res;
    }
}

int main() {
    int q;
    scanf("%d %d %d", &n, &m, &q);
    FO(i,0,n) {
        scanf("%s", g[i]);
    }
    initrt(0,0,n);
    FO(_,0,q) {
        char ch; scanf(" %c", &ch);
        if (ch == 'C') {
            int x, y;
            scanf("%d %d %c", &y, &x, &ch);
            g[y-1][x-1] = ch;
            rebuild(0,0,n,y-1);
        } else {
            int x, y;
            scanf("%d %d", &y, &x);
            ii dest = gthingy(0,0,n,0,y).go[x-1];
            printf("%d %d\n", dest.y+1, dest.x+1);
        }
    }
}
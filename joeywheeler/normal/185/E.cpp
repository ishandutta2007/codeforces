#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define y first
#define x second
#define p pair<int,int>

struct nd {
    nd *l, *r;
    int cp;
};

nd lmmlc[4000005];
int mlci;

nd *newnd() {
    return lmmlc+mlci++;
}

nd *ap(nd *i, int rs, int re, int qi) {
    nd *res = newnd();
    if (i) *res = *i;
    if (rs+1 == re) res->cp++;
    else {
        int md = (rs+re)/2;
        if (qi < md)
            res->l = ap(res->l, rs, md, qi);
        else
            res->r = ap(res->r, md, re, qi);
        res->cp = 0;
        if (res->l) res->cp += res->l->cp;
        if (res->r) res->cp += res->r->cp;
    }
    return res;
}

int hp(nd *i, int rs, int re, int qs, int qe) {
    if (!i) return 0;
    if (rs == qs && re == qe) return i->cp;
    else {
        int md = (rs+re)/2;
        int res = 0;
        if (qs < md) res += hp(i->l, rs, md, qs, min(qe,md));
        if (qe > md) res += hp(i->r, md, re, max(qs,md), qe);
        return res;
    }
}

int n, k;
p d[100005];
p s[100005];
vector<int> cx, cy;
nd *rt[100005];
vector<int> ev[100005];
pair<int,int> o[100005];

bool rq(int lx, int rx, int ly, int ry) {
    lx = lower_bound(cx.begin(),cx.end(),lx)-cx.begin();
    rx = upper_bound(cx.begin(),cx.end(),rx)-cx.begin()-1;
    ly = lower_bound(cy.begin(),cy.end(),ly)-cy.begin();
    ry = upper_bound(cy.begin(),cy.end(),ry)-cy.begin()-1;

    return hp(rt[rx],0,sz(cy),ly,ry+1) - 
        hp(rt[lx-1],0,sz(cy),ly,ry+1) > 0;
}

pair<int,int> ocd[200005];
int b[200005];

void ub(int i, int v) {
    for (i++; i < 200005; i += i&-i) b[i] = max(b[i],v);
}

int qb(int i) {
    int v = -1e9;
    for (i++; i > 0; i -= i&-i) v = max(v,b[i]);
    return v;
}

void calcdists() {
    FO(i,0,n) o[i] = {4e8+5,i};
    FO(Z,0,4) {
        FO(i,0,n) d[i] = {d[i].x, -d[i].y};
        FO(i,0,k) s[i] = {s[i].x, -s[i].y};

        FO(i,0,200005) b[i] = -1e9;

        vector<int> y;
        FO(i,0,n) y.push_back(d[i].y);
        FO(i,0,k) y.push_back(s[i].y);
        sort(y.begin(),y.end());
        y.resize(unique(y.begin(),y.end())-y.begin());

        FO(i,0,n) ocd[i] = make_pair(d[i].x, i);
        FO(i,0,k) ocd[i+n] = make_pair(s[i].x, ~i);
        sort(ocd,ocd+n+k);
        FO(j,0,n+k) {
            int i = ocd[j].second;
            if (i < 0) {
                i = ~i;
                ub(lower_bound(y.begin(),y.end(),s[i].y)-y.begin(),s[i].y+s[i].x);
            } else {
                //printf("i=%d, %d,%d\n", i, d[i].x, d[i].y);
                int qa = qb(lower_bound(y.begin(),y.end(),d[i].y)-y.begin());
                //printf("%d, %d\n", d[i].y+d[i].x, qa);
                o[i].first = min(o[i].first, d[i].y+d[i].x - qa);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    FO(i,0,n) {
        scanf("%d %d", &d[i].x, &d[i].y);
    }
    FO(i,0,k) {
        scanf("%d %d", &s[i].x, &s[i].y);
    }
    calcdists();
    //FO(i,0,n) printf("dst(%d)=%d\n", i, o[i].first);
    FO(i,0,n) d[i] = {d[i].x+d[i].y,d[i].x-d[i].y};
    FO(i,0,k) s[i] = {s[i].x+s[i].y,s[i].x-s[i].y};
    FO(i,0,k) {
        cx.push_back(s[i].x);
        cy.push_back(s[i].y);
    }
    cx.push_back(-1e9); cx.push_back(1e9);
    cy.push_back(-1e9); cy.push_back(1e9);
    sort(cx.begin(),cx.end());
    cx.resize(unique(cx.begin(),cx.end())-cx.begin());
    sort(cy.begin(),cy.end());
    cy.resize(unique(cy.begin(),cy.end())-cy.begin());
    
    FO(i,0,k) {
        int ci = lower_bound(cx.begin(), cx.end(), s[i].x)-cx.begin();
        ev[ci].push_back(i);
    }
    FO(i,1,sz(cx)) {
        rt[i] = rt[i-1];
        for (int j : ev[i]) {
            int ci = lower_bound(cy.begin(), cy.end(), s[j].y)-cy.begin();
            rt[i] = ap(rt[i], 0, sz(cy), ci);
        }
    }

    sort(o,o+n,greater<pair<int,int> >());
    int s = 0, e = 4e8+3, b = 4e8+3;
    while (s <= e) {
        int md = (s+e)/2;
        int lx = -2e8+5, rx = 2e8+5;
        int ly = -2e8+5, ry = 2e8+5;
        bool good = false;
        FO(j,0,n) {
            int i = o[j].second;
            int r = md - o[j].first;
            if (r >= 0) {
                // consider i and onwards teleport
                good |= rq(lx-r,rx+r,ly-r,ry+r);
                if (good) break;
            }
            // consider i doesn't teleport
            lx = max(lx, d[i].x-md); rx = min(rx, d[i].x+md);
            ly = max(ly, d[i].y-md); ry = min(ry, d[i].y+md);
            if (lx > rx || ly > ry) break;
        }
        good |= lx <= rx && ly <= ry;
        if (good) {
            b = md;
            e = md-1;
        } else {
            s = md+1;
        }
    }
    printf("%d\n", b);
}
#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())
#define get(a,b,c) ((a)==NULL?(c):(a)->b)

using namespace std;

int seen[100005], prv[100005];
queue<int> q;
int a[100005], b[100005], c[100005], d[100005];

int cd, cp;

typedef struct _rnode {
    _rnode *l, *r;
    set<pair<int,int> > s;

    _rnode() : l(NULL), r(NULL), s() {}
} *rnode;

void setv(rnode nd, int ys, int ye, int y, int x, int i) {
    nd->s.insert(make_pair(x,i));
    if (ys+1 == ye) {
    } else {
        if (nd->l == NULL) nd->l = new _rnode;
        if (nd->r == NULL) nd->r = new _rnode;

        int md = (ys+ye)/2;
        if (y < md) {
            setv(nd->l, ys, md, y, x, i);
        } else {
            setv(nd->r, md, ye, y, x, i);
        }
    }
}

void outp(set<pair<int,int> > &s, int xs, int xe) {
    // push i from xs to xe
    auto it = s.end();
    while ((it = s.lower_bound(make_pair(xs,-1))) != s.end()) {
        if (it ->first > xe) break;
        if (!seen[it->second]) {
            q.push(it->second);
            seen[it->second] = cd;
            prv[it->second] = cp;
        }
        s.erase(it);
    }
}

void query(rnode nd, int rs, int re, int ys, int ye, int xs, int xe) {
    if (nd == NULL) return;
    if (ys == rs && ye == re) {
        return outp(nd->s, xs, xe);
    } else {
        int md = (rs+re)/2;
        if (ys < md) query(nd->l, rs, md, ys, min(md, ye), xs, xe);
        if (ye > md) query(nd->r, md, re, max(md, ys), ye, xs, xe);
    }
}


int main() {
    int n; scanf("%d", &n);
    rnode root = new _rnode;
    FO(i,0,n) {
        scanf("%d%d%d%d", a+i, b+i, c+i, d+i);
        setv(root, 0, 1e9+5, c[i], d[i], i);
    }
    setv(root, 0, 1e9+5, 0, 0, n);
    q.push(n-1);
    seen[n-1] = 1;
    prv[n-1] = -1;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (i == n) break;
        cd = seen[i]+1; cp = i;
        query(root, 0, 1e9+5, a[i], 1e9+5, b[i], 1e9+5);
    }
    printf("%d\n", seen[n]-1);
    if (seen[n]) {
        for (int i = prv[n]; i != -1; i = prv[i]) printf("%d%c", i+1, " \n"[prv[i]==-1]);
    }
}
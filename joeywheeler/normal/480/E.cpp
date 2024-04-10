#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w, n;
char g[2005][2005];
int yy[2005], xx[2005];
int tdp[2005][2005];
int res[2005];
set<int> s[2005];

struct MAGIC_QUEUE {
    queue<int> q;
    multiset<int> qv;

    void push(int x) {
        q.push(x);
        qv.insert(x);
    }

    int getmin() {
        return *qv.begin();
    }

    void pop() {
        qv.erase(qv.find(q.front()));
        q.pop();
    }
};

int getr(int y, int x) {
    set<int>::iterator it = s[y].lower_bound(x);
    if (it != s[y].end()) return *it;
    else return w;
}

int getl(int y, int x) {
    if (s[y].empty()) return -1;
    set<int>::iterator it = s[y].lower_bound(x);
    while (it != s[y].begin() && (it == s[y].end() || *it > x)) --it;
    if (*it <= x) return *it;
    else return -1;
}

int calc(int x) {
    // find best containing x as one of it's rows
    MAGIC_QUEUE l, r;
    int i0 = 0, i1 = 0;
    l.push(x-getl(0,x));
    r.push(getr(0,x)-x);
    int cr=0;
    while (i0 < h && i1 < h) {
        if (l.getmin()==0 || r.getmin()==0) {
            if (i0 == i1) {
                i1++;
                l.push(x-getl(i1,x));
                r.push(getr(i1,x)-x);
            }
            i0++; l.pop(); r.pop();
        } else if (l.getmin()+r.getmin()-1 >= i1-i0+1) {
            cr = max(cr, i1-i0+1);
            i1++;
            l.push(x-getl(i1,x));
            r.push(getr(i1,x)-x);
        } else {
            i0++; l.pop(); r.pop();
        }
    }
    return cr;
}

int main() {
    scanf("%d %d %d", &h, &w, &n);
    FO(y,0,h) scanf(" %s", g[y]);
    FO(i,0,n) {
        scanf("%d %d", yy+i, xx+i);
        g[--yy[i]][--xx[i]] = 'X';
    }
    int cur=0;
    FO(y,0,h) FO(x,0,w) {
        if (g[y][x]=='.') {
            if (!y||!x) tdp[y][x]=1;
            else tdp[y][x]=1+min(min(tdp[y-1][x],tdp[y][x-1]),tdp[y-1][x-1]);
        } else {
            tdp[y][x]=0;
            s[y].insert(x);
        }
        cur = max(cur,tdp[y][x]);
    }
    for (int o = n-1; o >= 0; o--) {
        res[o] = cur;
        g[yy[o]][xx[o]] = '.';
        s[yy[o]].erase(xx[o]);
        cur=max(cur,calc(xx[o]));
    }
    FO(i,0,n) printf("%d\n", res[i]);
}
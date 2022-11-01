#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int x[200005], y[200005], t[200005], res[200005];

void go(set<int> &a, set<pair<int,int> > &sx, set<pair<int,int> > &sy, int lx, int ly) {
    if (a.empty()) return;
    int op = *a.begin();
    a.erase(op);
    sx.erase(make_pair(x[op],op));
    sy.erase(make_pair(y[op],op));
    if (t[op] == 'U') {
        int cp = x[op];
        res[op] = y[op]-ly;

        set<int> b; set<pair<int,int> > bx,by;
        auto li = sx.begin(); auto ri = sx.rbegin();
        while (li != sx.end() && li->first < cp &&
                ri != sx.rend() && ri->first >= cp) {
            li++; ri++;
        }
        bool bl;
        if (li == sx.end() || li->first >= cp) {
            bl = true;
            li = sx.begin();
            while (li != sx.end() && li->first < cp) {
                b.insert(li->second);
                li++;
            }
        } else {
            bl = false;
            ri = sx.rbegin();
            while (ri != sx.rend() && ri->first >= cp) {
                b.insert(ri->second);
                ri++;
            }
        }
        for (int i : b) {
            a.erase(i);
            sx.erase(make_pair(x[i], i));
            sy.erase(make_pair(y[i], i));
            bx.insert(make_pair(x[i], i));
            by.insert(make_pair(y[i], i));
        }
        if (bl) {
            go(b,bx,by,lx,ly);
            go(a,sx,sy,cp,ly);
        } else {
            go(b,bx,by,cp,ly);
            go(a,sx,sy,lx,ly);
        }
    } else {
        int cp = y[op];
        res[op] = x[op]-lx;

        set<int> b; set<pair<int,int> > bx,by;
        auto li = sy.begin(); auto ri = sy.rbegin();
        while (li != sy.end() && li->first < cp &&
                ri != sy.rend() && ri->first >= cp) {
            li++; ri++;
        }
        bool bl;
        if (li == sy.end() || li->first >= cp) {
            bl = true;
            li = sy.begin();
            while (li != sy.end() && li->first < cp) {
                b.insert(li->second);
                li++;
            }
        } else {
            bl = false;
            ri = sy.rbegin();
            while (ri != sy.rend() && ri->first >= cp) {
                b.insert(ri->second);
                ri++;
            }
        }
        for (int i : b) {
            a.erase(i);
            sx.erase(make_pair(x[i], i));
            sy.erase(make_pair(y[i], i));
            bx.insert(make_pair(x[i], i));
            by.insert(make_pair(y[i], i));
        }
        if (bl) {
            go(b,bx,by,lx,ly);
            go(a,sx,sy,lx,cp);
        } else {
            go(b,bx,by,lx,cp);
            go(a,sx,sy,lx,ly);
        }
    }
}

set<pair<int,int> > opd;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    FO(i,0,q) {
        char ch;
        scanf("%d %d %c", &x[i], &y[i], &ch);
        t[i] = ch;
    }
    set<int> a; set<pair<int,int> > sx,sy;
    FO(i,0,q) {
        a.insert(i);
        sx.insert(make_pair(x[i],i));
        sy.insert(make_pair(y[i],i));
    }
    go(a,sx,sy,0,0);
    FO(i,0,q) {
        if (opd.count(make_pair(x[i],y[i]))) res[i] = 0;
        opd.insert(make_pair(x[i],y[i]));
        printf("%d\n", res[i]);
    }
}
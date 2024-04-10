#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct _nd {
    _nd *l, *r;
    int p, v, s;

    _nd() : l(0), r(0), p(rand()), v(0), s(1) {}

    void fix() {
        s = 1;
        if (l) s += l->s;
        if (r) s += r->s;
    }
};
typedef _nd *nd;

nd merge(nd a, nd b) {
    if (!a) return b;
    if (!b) return a;
    if (a->p > b->p) {
        a->r = merge(a->r,b);
        a->fix();
        return a;
    } else {
        b->l = merge(a,b->l);
        b->fix();
        return b;
    }
}

pair<nd,nd> split(nd a, int p) {
    if (!a) {
        //assert(p == 0);
        return make_pair(a,a);
    }
    //assert(p <= a->s);
    int ls = 0;
    if (a->l) ls += a->l->s;
    nd x, y;
    if (p <= ls) {
        tie(x,y) = split(a->l,p);
        a->l = y;
        a->fix();
        //assert(!x && !p || x->s == p);
        return {x,a};
    } else {
        tie(x,y) = split(a->r,p-ls-1);
        a->r = x;
        a->fix();
        //assert(!a && !p || a->s == p);
        return {a,y};
    }
}

int p[1000005];
int u[1000005];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    nd root = 0;
    FO(i,0,n) {
        nd d = new _nd;
        d->v = i;
        root = merge(root,d);
    }
    FO(i,0,m) {
        int v, l; scanf("%d %d", &v, &l);
        nd a,b,c;
        tie(a,b) = split(root,l-1);
        tie(b,c) = split(b,1);


        int oi = b->v;
        if (p[oi] == 0) {
            if (u[v]) {
                printf("-1\n");
                return 0;
            }
            p[oi] = v;
            u[v] = 1;
        }
        if (p[oi] != v) {
            printf("-1\n");
            return 0;
        }
        root = merge(merge(b,a),c);
    }

    int uu = 1;
    FO(i,0,n) {
        if (!p[i]) {
            while (u[uu]) uu++;
            u[uu] = 1;
            p[i] = uu;
        }
        printf("%d%c", p[i], " \n"[i+1==n]);
    }
}
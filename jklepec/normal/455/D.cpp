#include<bits/stdc++.h>
using namespace std;

struct item {
    int prior;
    int cnt;
    int val;
    bool lft;
    item * brat, * par;
    item * l, * r;
    item() { }
    item (int _p, int _c, int _v) {
        brat = par = l = r = NULL;
        prior = _p;
        cnt = _c;
        val = _v;
        lft = false;
    }
};
typedef item * pitem;

int num(pitem x) {
    return x ? x->cnt : 0;
}

int penji(pitem t, bool ok) {
    if(!t) return false;
    int ret = 0;
    if(!ok) {
        ret += num(t->l) + 1;
    }
    ret += penji(t->par, t->lft);
    return ret;
}

void upd(pitem par, pitem ch, bool lft) {
    if(ch) {
        ch->par = par;
        ch->lft = lft;
    }
}

void refresh(pitem x) {
    if(!x) return;
    x->cnt = 1 + num(x->l) + num(x->r);
}

void split (pitem t, int key, pitem & l, pitem & r, bool malo) {
    int cur_key = 0;
    if(t) {
        if(malo) {
            cur_key = penji(t->brat, false) - 1;
        } else {
            cur_key = penji(t, false) - 1;
        }
        //cout << t->val << " " << cur_key << endl;
    }
    if (!t)
        l = r = NULL;
    else if (key <= cur_key) {
        split (t->l, key, l, t->l, malo),  r = t;
        upd(0, l, false);
        upd(t, t->l, true);
    } else {
        split (t->r, key, t->r, r, malo),  l = t;
        upd(0, r, false);
        upd(t, t->r, false);
    }
    refresh(l);
    refresh(r);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior) {
        merge (l->r, l->r, r),  t = l;
    } else {
        merge (r->l, l, r->l),  t = r;
    }
    if(t) {
        upd(t, t->l, true);
        upd(t, t->r, false);
        refresh(t);
    }
}

const int MAXN = 1e6 + 5;

pitem Strpa[MAXN];

int lans;
int n;

int correct(int x) {
    return (x + lans - 1) % n + 1;
}

void ispisi(pitem x) {
    if(!x) return;
    cout << x->val << endl;
    cout << "lijevo" << endl;
    ispisi(x->l);
    cout << "desno" << endl;
    ispisi(x->r);
}

#define REP(i, n) for(int i = 0; i < n; ++i)

int main() {
    cin >> n;
    REP(i, n) {
        int x; cin >> x;

        pitem vel = new item(rand(), 1, x);
        pitem mal = new item(rand(), 1, x);

        vel->brat = mal;
        mal->brat = vel;

        merge(Strpa[0], Strpa[0], vel);
        merge(Strpa[x], Strpa[x], mal);
    }

    int q; cin >> q;
    REP(i, q) {
        int t, l, r;
        cin >> t >> l >> r;
        l = correct(l);
        r = correct(r);
        l --; r --;
        if(l > r) swap(l, r);
        if(t == 1) {
            if(l == r) continue;

            pitem X, Y, Z, Q;
            split(Strpa[0], r + 1, X, Z, false);
            split(X, r, X, Y, false);

            int k = Y->val;
            merge(X, X, Y);
            merge(Strpa[0], X, Z);

            bool arg = true;
            for(int x: {k, 0}) {
                split(Strpa[x], r + 1, X, Q, arg);
                split(X, r, X, Z, arg);
                split(X, l, X, Y, arg);

                merge(X, X, Z);
                merge(X, X, Y);
                merge(Strpa[x], X, Q);
                arg = false;
            }
        } else {
            int k; cin >> k;
            k = correct(k);
            //cout << l << r << k << endl;
            pitem X = NULL, Y = NULL, Z = NULL;
            split(Strpa[k], r + 1, X, Z, true);
            split(X, l, X, Y, true);

            lans = Y ? Y->cnt : 0;
            cout << lans << "\n";
            merge(X, X, Y);
            merge(Strpa[k], X, Z);
        }
    }
}
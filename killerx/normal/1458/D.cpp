#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int inf = 0x3f3f3f3f;

mt19937 rng;

struct Node {
    bool rev, flip;
    int v, s, mnsp, mxsp, mnss, mxss, sz, fix;
    Node *ls, *rs;

    Node(int _v):
        rev(0), flip(0), v(_v), s(_v),
        mnsp(_v), mxsp(_v), mnss(_v), mxss(_v),
        sz(1), fix(rng()), ls(nullptr), rs(nullptr) { }

    inline void pushrev() { rev ^= 1; swap(ls, rs); swap(mnsp, mnss); swap(mxsp, mxss); }

    inline void pushflip() { flip ^= 1; v *= -1; s *= -1; swap(mnsp, mxsp); swap(mnss, mxss); mnsp *= -1; mxsp *= -1; mnss *= -1; mxss *= -1; }

    inline void pushdown() {
        if (rev) { if (ls) ls->pushrev(); if (rs) rs->pushrev(); rev = 0; }
        if (flip) { if (ls) ls->pushflip(); if (rs) rs->pushflip(); flip = 0; }
    }

    inline void pushup() {
        sz = 1 + (ls ? ls->sz : 0) + (rs ? rs->sz : 0);
        s = v + (ls ? ls->s : 0) + (rs ? rs->s : 0);
        mnsp = min(ls ? ls->mnsp : inf, (ls ? ls->s : 0) + v + (rs ? min(0, rs->mnsp) : 0));
        mxsp = max(ls ? ls->mxsp : -inf, (ls ? ls->s : 0) + v + (rs ? max(0, rs->mxsp) : 0));
        mnss = min(rs ? rs->mnss : inf, (rs ? rs->s : 0) + v + (ls ? min(0, ls->mnss) : 0));
        mxss = max(rs ? rs->mxss : -inf, (rs ? rs->s : 0) + v + (ls ? max(0, ls->mxss) : 0));
    }
};

Node *join(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    a->pushdown(); b->pushdown();
    if (a->fix < b->fix) { a->rs = join(a->rs, b); a->pushup(); return a; }
    else { b->ls = join(a, b->ls); b->pushup(); return b; }
}

void split(Node *x, int k, Node *&a, Node *&b) {
    if (!x) return void(a = b = nullptr);
    x->pushdown();
    int lsz = x->ls ? x->ls->sz : 0;
    if (lsz + 1 <= k) { a = x; split(x->rs, k - lsz - 1, a->rs, b); a->pushup(); }
    else { b = x; split(x->ls, k, a, b->ls); b->pushup(); }
}

int fless(Node *x, int v) {
    x->pushdown();
    if (x->mnsp >= v) return -1;
    if (x->ls && x->ls->mnsp < v) return fless(x->ls, v);
    else if ((x->ls ? x->ls->s : 0) + x->v < v) return (x->ls ? x->ls->sz : 0);
    else return fless(x->rs, v - (x->ls ? x->ls->s : 0) - x->v) + (x->ls ? x->ls->sz : 0) + 1;
}

int fgreater(Node *x, int v) {
    x->pushdown();
    if (x->mxsp <= v) return -1;
    if (x->ls && x->ls->mxsp > v) return fgreater(x->ls, v);
    else if ((x->ls ? x->ls->s : 0) + x->v > v) return (x->ls ? x->ls->sz : 0);
    else return fgreater(x->rs, v - (x->ls ? x->ls->s : 0) - x->v) + (x->ls ? x->ls->sz : 0) + 1;
}

void print(Node *x) {
    if (!x) return ;
    x->pushdown();
    if (x->ls) print(x->ls);
    putchar(x->v == +1 ? '1' : '0');
    if (x->rs) print(x->rs);
}

void println(Node *x) {
    print(x);
    puts("");
}

int n;
char s[500005];
Node *rt;

void Main() {
    scanf("%s", s);
    n = strlen(s);
    rt = nullptr;
    rep(i, n) rt = join(rt, new Node(s[i] == '1' ? +1 : -1));
    rep(i, n) {
        int si = 0;
        {
            Node *a, *b, *c;
            split(rt, i, a, b);
            split(b, 1, b, c);
            si = b->v;
            rt = join(join(a, b), c);
        }
        if (si == 1) {
            Node *a, *b, *c;
            split(rt, i, a, b);
            int k = fless(b, 0);
            if (k != -1) {
                int ni = i + k;
                split(b, k, b, c);
                int l = fgreater(c, -1);
                if (l != -1) {
                    int nni = ni + l;
                    b = join(b, c);
                    split(b, nni - i + 1, b, c);
                    b->pushrev();
                    b->pushflip();
                }
                rt = join(join(a, b), c);
            } else {
                c = nullptr;
                rt = join(a, b);
            }
        }
    }
    // brute:
    // rep(i, n) if (s[i] == '1') {
    //     int bal = 0, ok = -1;
    //     for (int j = i; j < n; ++ j) {
    //         bal += s[j] == '1' ? +1 : -1;
    //         if (bal == 0 && s[j] == '1') {
    //             ok = j;
    //             break;
    //         }
    //     }
    //     if (ok != -1) {
    //         reverse(s + i, s + ok + 1);
    //         for (int j = i; j <= ok; ++ j) s[j] ^= 1;
    //     }
    // }
    println(rt);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}
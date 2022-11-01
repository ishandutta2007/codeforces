#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int m1 = 1000000007;
const int m2 = 1000000009;
int p1, p2;

const int maxn = 100500;

i64 pp1[maxn], pp2[maxn];
i64 sp1[maxn], sp2[maxn];

struct H {
    int v1, v2, len;
    bool operator==(const H& o) { return v1 == o.v1 && v2 == o.v2; }
};

H operator+(const H& a, const H& b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    int v1 = (pp1[a.len] * b.v1 + a.v1) % m1;
    int v2 = (pp2[a.len] * b.v2 + a.v2) % m2;
    return { v1, v2, a.len + b.len };
}

int n, q1, q2;
char s[maxn];

struct node {
    int l, r;
    H h;
    int paint;
    node *L, *R;

    node(int l, int r) : l(l), r(r), paint(-1) {
        if (l == r) {
            h = { s[l], s[l], 1 };
            L = R = NULL;
        } else {
            L = new node(l, (l+r)/2);
            R = new node((l+r)/2+1, r);
            h = L->h + R->h;
        }
    }

    H get() const {
        if (paint == -1) return h;
        else return {
            int((sp1[r-l+1] * paint) % m1),
            int((sp2[r-l+1] * paint) % m2),
            r-l+1
        };
    }

    void push() {
        if (paint != -1) {
            if (L) L->paint = R->paint = paint;
            h = get();
        }
        paint = -1;
    }

    void upd() {
        assert(paint == -1);
        if (paint == -1 && L) {
            h = L->get() + R->get();
        }
    }

    H get(int lq, int rq) {
        push();
        if (lq <= l && rq >= r) {
            return get();
        } else if (lq > r || rq < l) {
            return {0,0,0};
        } else {
            push();
            return L->get(lq, rq) + R->get(lq, rq);
        }
    }

    void put(int lq, int rq, int v) {
        push();
        if (lq <= l && rq >= r) {
            paint = v;
        } else if (lq > r || rq < l) {
            ;
        } else {
            push();
            L->put(lq, rq, v);
            R->put(lq, rq, v);
            upd();
        }
    }
};

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d%d", &n, &q1, &q2);
    scanf("%s", s);
    int S = 0;
    forn(i, n) S = S * 10099 + s[i];
    srand(S);

    p1 = (rand() * 10000 + 1000) * 2 + 1;
    p2 = (rand() * 10000 + 1000) * 2 + 1;

//     p1 = 10;
//     p2 = 100;

    pp1[0] = pp2[0] = 1;
    sp1[0] = sp2[0] = 0;

    forn(i, n+1) if (i) {
        pp1[i] = pp1[i-1] * p1 % m1;
        pp2[i] = pp2[i-1] * p2 % m2;

        sp1[i] = (sp1[i-1] + pp1[i-1]) % m1;
        sp2[i] = (sp2[i-1] + pp2[i-1]) % m2;
    }

//     forn(i, n) cout << pp1[i] << " "; cout << endl;
//     forn(i, n) cout << sp1[i] << " "; cout << endl;

    node *root = new node(0, n-1);

    forn(i, q1+q2) {
        int t, l, r, c;
        scanf("%d%d%d%d", &t, &l, &r, &c), --l, --r;
        if (t == 1) {
            root->put(l, r, c+'0');
        } else {
            H h1 = root->get(l, r-c);
            H h2 = root->get(l+c, r);
            if (h1 == h2) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
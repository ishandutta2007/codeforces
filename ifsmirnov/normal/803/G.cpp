#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;
const int inf = 1e9+100500;

struct node {
    int l, r;
    node *L, *R;
    int mn;
    int add;

    node(int l, int r) : l(l), r(r), mn(inf), add(0) {
        if (l+1 == r) {
            L = R = NULL;
        } else {
            int m = (l+r)/2;
            L = new node(l, m);
            R = new node(m, r);
        }
    }

    void apply(int x) {
        add = mn = x;
    }

    void push() {
        if (add) {
            L->apply(add);
            R->apply(add);
            add = 0;
        }
    }

    void update() {
        mn = min(L->mn, R->mn);
    }

    void put(int lq, int rq, int val) {
        if (lq <= l && r <= rq) {
            apply(val);
        } else if (rq <= l || lq >= r) {
        } else {
            push();
            L->put(lq, rq, val);
            R->put(lq, rq, val);
            update();
        }
    }

    int get(int lq, int rq) {
        if (lq <= l && r <= rq) {
            return mn;
        } else if (rq <= l || lq >= r) {
            return inf;
        } else {
            push();
            return min(L->get(lq, rq), R->get(lq, rq));
        }
    }
};

const int maxn = 500500;

int n, k;
int b[maxn];
int q;
int t[maxn], l[maxn], r[maxn], x[maxn];
vi shr;

node *t1, *t2;

void scan() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", &b[i]);
    scanf("%d", &q);
    forn(i, q) {
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            scanf("%d%d%d", &l[i], &r[i], &x[i]);
        } else {
            scanf("%d%d", &l[i], &r[i]);
        }
        --l[i];
    }
}

void solve() {
    forn(i, k+1) shr.pb(i*n);
    forn(i, q) shr.pb(l[i]), shr.pb(r[i]);
    sort(all(shr));
    shr.erase(unique(all(shr)), shr.end());

    int k = shr.size();

    t1 = new node(0, n);
    forn(i, n) t1->put(i, i+1, b[i]);
    t2 = new node(0, k);
    forn(i, k-1) {
        int l = shr[i], r = shr[i+1];
        int lq = l%n, rq = r%n;
        if (rq == 0) rq = n;
        t2->put(i, i+1, t1->get(lq, rq));
    }

    forn(i, q) {
        int lq = lower_bound(all(shr), l[i]) - shr.begin();
        int rq = lower_bound(all(shr), r[i]) - shr.begin();
        if (t[i] == 1) {
            t2->put(lq, rq, x[i]);
        } else {
            printf("%d\n", t2->get(lq, rq));
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("g.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
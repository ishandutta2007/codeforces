#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
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
const int maxn = 500500;

#define assert(...)

const int K = 720;

int a[maxn];
unordered_set<int> bl[maxn];
int ad[maxn];
int n, q;

void upd(int b) {
    assert(ad[b] == 0);
    bl[b].clear();
    for (int i = b*K; i < min(n, b*K+K); ++i) {
        if (a[i] != inf) {
            bl[b].insert(a[i]);
        }
    }
//     bl[b].insert(a+b*K, a+min(n, b*K+K));
}

void push(int b) {
    if (ad[b]) {
        fore(i, b*K, b*K+K-1) {
            if (i == n) break;
            a[i] = min(a[i] + ad[b], inf);
        }
    }
    ad[b] = 0;
}

void upd(int lq, int rq, int x) {
    int lb = lq / K, rb = rq / K;
    if (lb == rb) {
        push(lb);
        fore(i, lq, rq) a[i]  = min(a[i] + x, inf);
        upd(lb);
        return;
    }

    push(lb);
    fore(i, lq, lb*K+K-1) a[i] = min(a[i] + x, inf);
    upd(lb);

    fore(i, lb+1, rb-1) ad[i] = min(ad[i] + x, inf);

    push(rb);
    fore(i, rb*K, rq) a[i] = min(a[i] + x, inf);
    upd(rb);
}

bool in(int b, int x) {
    return x > ad[b] && bl[b].count(x - ad[b]);
}

int left(int l, int r, int x) {
    int b = l/K;
    assert(r/K == b);
    x -= ad[b];
    assert(x > 0);
    while (l <= r) {
        if (a[l] == x) return l;
        ++l;
    }
    return -1;
}

int right(int l, int r, int x) {
    int b = l/K;
    assert(r/K == b);
    x -= ad[b];
    assert(x > 0);
    while (l <= r) {
        if (a[r] == x) return r;
        --r;
    }
    return -1;
}

int get(int x) {
    int lp = -1, rp = -1;

    forn(i, (n+K-1)/K) if (in(i, x)) {
        lp = left(i*K, min(n, i*K+K)-1, x);
        break;
    }
    if (lp == -1) return -1;

    ford(i, (n+K-1)/K) if (in(i, x)) {
        rp = right(i*K, min(n, i*K+K)-1, x);
        break;
    }
    assert(rp != -1);
    return rp - lp;
}

void scan() {
    scanf("%d%d", &n, &q);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, (n+K-1)/K) upd(i);
}

void solve() {
    int t, l, r, x;
    forn(i, q) {
        scanf("%d%d", &t, &l);
        if (t == 1) {
            scanf("%d%d", &r, &x), --l, --r;
            upd(l, r, x);
        } else {
            printf("%d\n", get(l));
        }
//         forn(j, n) printf("%d ", a[j] + ad[j/K]); printf("\n");
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
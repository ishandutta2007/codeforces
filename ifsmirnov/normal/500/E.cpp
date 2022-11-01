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
const int maxn = 200500;

int p[maxn];
void init() {
    forn(i, maxn) p[i] = i;
}
int get(int x) { return x == p[x] ? x : (p[x] = get(p[x])); }
void unite(int x, int y) {
    p[get(y)] = get(x);
}

int fen[maxn];
int fget(int i) {
    int s = 0;
    for (; i >= 0; i = (i&(i+1))-1) {
        s += fen[i];
    }
    return s;
}
void add(int i, int x) {
    for (; i < maxn; i |= (i+1)) {
        fen[i] += x;
    }
}

int n, m;
int x[maxn], h[maxn];
vi st;
int res[maxn];
struct Q {
    int l, r, id;
    bool operator<(const Q& q) const { return l > q.l; }
};
Q q[maxn];
int lx;

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", &x[i], &h[i]);
    }
    scanf("%d", &m);
    forn(i, m) {
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l; --q[i].r; q[i].id = i;
    }
    sort(q, q+m);
}

void add_domino(int i) {
    int cr = x[i] + h[i];
    while (!st.empty() && x[st.back()] <= cr) {
        int t = st.back();
        st.pop_back();
        unite(i, t);
        cr = max(cr, x[t] + h[t]);
        add(t, -h[t]);
        h[t] = 0;
    }
    st.pb(i);
    lx = x[i];
    h[i] = cr - x[i];
    add(i, h[i]);
//     cout << "add " << i << endl;
//     cout << "cur stack: ";
//     forn(i, st.size()) {
//         cout << "(" << x[st[i]] << ", " << h[st[i]] << ")  ";
//     }
//     cout << endl;
}

int query(int y) {
    y = get(y);
    return max(0, x[y] - lx - fget(y-1));
}

void solve() {
    int px = n;
    forn(i, m) {
        while (px > q[i].l) {
            add_domino(--px);
        }
        res[q[i].id] = query(q[i].r);
    }
    forn(i, m) printf("%d\n", res[i]);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    init();
    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
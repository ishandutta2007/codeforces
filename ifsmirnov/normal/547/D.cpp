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

int x[maxn], y[maxn], rn, n;
int res[maxn];

int cx[maxn], cy[maxn];

vi bx[maxn], by[maxn];
vi ox, oy;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d", &x[i], &y[i]);
    rn = n;
}

void check() {
    forn(i, rn) {
        if (res[i] == 1) ++cx[x[i]], ++cy[y[i]];
        else --cx[x[i]], --cy[y[i]];
    }
    forn(i, 200001) assert(abs(cx[i]) <= 1 && abs(cy[i]) <= 1);
}

void pre() {
    forn(i, n) {
        bx[x[i]].pb(i);
        by[y[i]].pb(i);
    }
    forn(i, 200500) {
        if (bx[i].size() % 2) ox.pb(i);
        if (by[i].size() % 2) oy.pb(i);
    }
    assert(ox.size() % 2 == oy.size() % 2);
    ford(i, ox.size() - oy.size()) oy.pb(300000);
    ford(i, oy.size() - ox.size()) ox.pb(300000);
    assert(ox.size() == oy.size());
    forn(i, ox.size()) {
        x[n] = ox[i];
        y[n] = oy[i];
        bx[ox[i]].pb(n);
        by[oy[i]].pb(n);
        ++n;
    }
}

void solve() {
    forn(i, n) if (!res[i]) {
        int c = 1, j = i;
        do {
            res[j] = c;
            vi& sel = c == 1 ? bx[x[j]] : by[y[j]];
            while (!sel.empty() && res[sel.back()]) {
                sel.pop_back();
            }
            if (sel.empty()) {
                break;
            }
            j = sel.back();
            sel.pop_back();
            c = 3 - c;
        } while (i != j);
    }

    forn(i, rn) {
        assert(res[i]);
        printf("%c", " br"[res[i]]);
    }
    printf("\n");
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    pre();
    solve();
    check();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
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

const int maxn = 21;
char c[maxn][maxn];
vector<pii> v;
int a[maxn][maxn];
int ss[50];
int d[1<<20];
int n, m;

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%s", c[i]);
        forn(j, m) c[i][j] -= 'a';
    }
    forn(i, n) forn(j, m) scanf("%d", &a[i][j]);
}

void comp() {
    forn(i, n) forn(j, m) {
        int cc = 0;
        int mm = 1<<i;
        forn(k, n) if (k != i && c[i][j] == c[k][j]) {
            cc += a[k][j];
            mm ^= 1<<k;
        }
        v.pb(mp(cc, mm));
    }
    forn(i, n) {
        v.pb(mp(*min_element(a[i], a[i]+m), 1<<i));
    }
}

void relax(int &x, int y) { x = min(x, y); }

void solve() {
    comp();
    forn(i, 1<<n) d[i] = inf;
    d[0] = 0;
    forn(mm, 1<<n) {
        assert(d[mm] != inf);
        for (auto p: v) {
            relax(d[mm|p.se], d[mm] + p.fi);
        }
    }
    cout << d[(1<<n)-1] << endl;
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
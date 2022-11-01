#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <cstdlib>
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
const int inf = 10050;
const int maxn = 102;

bool prime(int x) {
    for (int i = 2; i < x; ++i) if (x%i == 0) return false;
    return true;
}

int pr[100];
int rpr[100];
int npr = 0;
void genpr() {
    for (int i = 1; i <= 60; ++i) if (prime(i)) {
        rpr[i] = npr;
        pr[npr++] = i;
    }
}

int n;
int a[maxn];
int ss = 0;
int sp[maxn];
short d[maxn][1<<18];
char anc[maxn][1<<18];

int ff[maxn];
int nf;
void factor(int x) {
    nf = 0;
    for (int i = 2; i*i <= x; ++i) {
        if (x%i == 0) {
            ff[nf++] = i;
            while (x%i == 0) x /= i;
        }
    }
    if (x != 1) ff[nf++] = x;
}
int mf[maxn];
void genmf() {
    fore(i, 1, 60) {
        factor(i);
        forn(j, nf) mf[i] |= 1<<rpr[ff[j]];
    }
}

void solve() {
    forn(i, n+1) forn(mask, 1<<18) d[i][mask] = inf;
    d[0][0] = 0;
    forn(i, n) forn(mask, 1<<18) if (d[i][mask] != inf) {
//         cout << i << " " << mask << endl;
        if (d[i][mask] + sp[i] > ss) continue;
        fore(t, 1, 60) {
            int dx = abs(t - a[i]);
//             if (d[i][mask] + dx > ss) continue;
            int nmask = mf[t];
//             cout << "  " << t << " " << nmask << endl;
            if (mask & nmask) {
            } else {
//                 cout << "relaxed" << endl;
                nmask |= mask;
                if (d[i+1][nmask] > d[i][mask] + dx) {
                    d[i+1][nmask] = d[i][mask] + dx;
                    anc[i+1][nmask] = t;
                }
            }
        }
//         cout << "d[1][0] = " << d[1][0] << endl;
//         cout << "end" << endl;
    }
    int mask = min_element(d[n], d[n]+(1<<18)) - d[n];
//     cerr << d[n][mask] << endl;
    vector<int> res;
    for (int i = n; i > 0; --i) {
        int v = anc[i][mask];
        res.pb(v);
        factor(v);
        forn(j, nf) mask &= ~(1<<rpr[ff[j]]);
    }
    reverse(all(res));
    forn(i, n) cout << res[i] << " "; cout << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    genpr();
    genmf();

    cin >> n;
    forn(i, n) cin >> a[i], ss += a[i] - 1;
    for (int i = n-1; i >= 0; --i) {
        sp[i] = sp[i+1] + a[i] - 1;
    }
    solve();


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
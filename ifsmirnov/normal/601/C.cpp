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

const int maxn = 105;
const int maxm = 1050;
typedef long double ld;

int n, k;
int r[100500];
ld d[maxn * maxm], sd[maxn * maxm], g[maxn * maxm];

void scan() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", &r[i]);
}

void ps(int to) {
    forn(i, maxn * maxm) {
        sd[i] = d[i];
        if (i) sd[i] += sd[i-1];
    }
}

ld ss(int i, int j) {
    if (i < 0) i = 0;
    if (j < 0) return 0;
    return sd[j] - (i ? sd[i-1] : 0);
}
int cnt(int i, int j) {
    assert(i <= j);
    if (j < 0) return 0;
    if (i < 0) return j+1;
    return j - i + 1;
}

void solve() {
    d[0] = 1;
    ps(1);

    for (int n = 1; n <= ::n; ++n) {
        for (int s = 0; s < n; ++s) {
            d[s] = 0;
        }
        for (int s = n; s <= n * k; ++s) {
            int cc = cnt(s-k, s-1);
            if (cc == 0) {
                d[s] = 0;
                continue;
            }
            ld t = ss(s-k, s-1);
            if (s >= r[n-1]) t -= ss(s-r[n-1], s-r[n-1]), --cc;
            if (cc) {
                d[s] = t / (k-1);
            } else {
                d[s] = 0;
            }
        }
        ps(n+1);
    }

    int total = 0;
    forn(i, n) total += r[i];

    ld pr = sd[total - 1];
    cout.precision(20);
    cout << fixed;
    cout << pr * (k-1) + 1 << endl;
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
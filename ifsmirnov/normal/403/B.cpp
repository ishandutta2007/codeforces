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
const int inf = 1e9+100500;
const int maxn = 100500;

vector<pii> factor(int n) {
    vector<pii> res;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            int cnt = 0;
            while (n%i == 0) n /= i, ++cnt;
            res.pb(mp(i, cnt));
        }
    }
    if (n != 1) res.pb(mp(n, 1));
    return res;
}

int n, m;
int a[maxn];
set<int> bad;

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    forn(i, m) {
        int x;
        scanf("%d", &x);
        bad.insert(x);
    }
}

int g(int x) {
    auto t = factor(x);
    int res = 0;
    for (auto p: t) {
        if (bad.count(p.fi)) res -= p.se;
        else res += p.se;
    }
    return res;
}

void solve() {
    int gm = 0;
    forn(i, n) gm += g(a[i]);
    int mx = gm;
    ford(i, n) {
        int gc = a[0];
        forn(j, i) gc = __gcd(gc, a[j+1]);
        int f = g(gc);
        if (f < 0) {
            mx -= f * (i+1);
            forn(j, i+1) a[j] /= gc;
        }
    }
    cout << mx << endl;
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
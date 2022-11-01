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

bool check(pair<pii, int> a[]) {
    int k = a[0].fi.fi;
    if (a[1].fi.fi + a[2].fi.fi != k) return false;
    if (a[1].fi.se != a[2].fi.se || a[1].fi.se + a[0].fi.se != k) return false;
    int s = 0;
    forn(i, 3) s += a[i].fi.fi * a[i].fi.se;
    assert(s == k*k);
    vector<string> t(k, string(k, ' '));
    forn(i, k) forn(j, k) {
        if (i < a[0].fi.se) t[i][j] = 'A' + a[0].se;
        else if (j < a[1].fi.fi) t[i][j] = 'A' + a[1].se;
        else t[i][j] = 'A' + a[2].se;
    }
    cout << k << endl;
    forn(i, k) cout << t[i] << endl;
    return true;
}

bool check2(pair<pii, int> a[]) {
    int k = a[0].fi.fi;
    forn(i, 3) if (a[i].fi.fi != k) return false;
    int s = 0;
    forn(i, 3) s += a[i].fi.fi * a[i].fi.se;
    if (s != k*k) return false;
    vector<string> t(k, string(k, ' '));
    forn(i, k) forn(j, k) {
        if (i < a[0].fi.se) t[i][j] = 'A' + a[0].se;
        else if (i < a[0].fi.se + a[1].fi.se) t[i][j] = 'A' + a[1].se;
        else t[i][j] = 'A' + a[2].se;
    }
    cout << k << endl;
    forn(i, k) cout << t[i] << endl;
    return true;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    pair<pii, int> a[3];
    forn(i, 3) cin >> a[i].fi.fi >> a[i].fi.se, a[i].se = i;

    forn(mask, 1<<3) {
        forn(i, 3) if (mask&(1<<i)) swap(a[i].fi.fi, a[i].fi.se);
        forn(I, 6) {
            if (check(a)) return 0;
            if (check2(a)) return 0;
            next_permutation(a, a+3);
        }
        forn(i, 3) if (mask&(1<<i)) swap(a[i].fi.fi, a[i].fi.se);
    }

    cout << -1 << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
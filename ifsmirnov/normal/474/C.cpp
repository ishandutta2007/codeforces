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

pii operator+(const pii& a, const pii& b) { return mp(a.fi+b.fi, a.se+b.se); }
pii operator-(const pii& a, const pii& b) { return mp(a.fi-b.fi, a.se-b.se); }


pii a[4], p[4];
void rotate(int i) {
    p[i] = p[i] - a[i];
    swap(p[i].fi, p[i].se);
    p[i].fi *= -1;
    p[i] = p[i] + a[i];
}

i64 dist(const pii& a, const pii& b) {
    i64 dx = a.fi - b.fi;
    i64 dy = a.se - b.se;
    return dx*dx+dy*dy;
}

bool sq() {
    vector<pii> p(::p, ::p+4);
    sort(all(p));
//     forn(i, p.size()) cout << p[i].fi << " " << p[i].se << endl;
    if (p[0] == p[3]) return false;
    if (p[0] + p[3] != p[1] + p[2]) return false;
    if (p[1] - p[0] != p[3] - p[2]) return false;
    if (p[2] - p[0] != p[3] - p[1]) return false;
    if (dist(p[0], p[1]) != dist(p[0], p[2])) return false;
    if (dist(p[0], p[1]) * 2ll != dist(p[0], p[3])) return false;
    return true;
}

int go(int pos, int s) {
    if (pos == 4) {
        return sq() ? s : inf;
    }
    int mn = inf;
    forn(k, 4) {
        mn = min(mn, go(pos+1, s+k));
        rotate(pos);
    }
    return mn;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    forn(j, n) {
        forn(i, 4) cin >> p[i].fi >> p[i].se >> a[i].fi >> a[i].se;
        int res = go(0, 0);
        if (res == inf) cout << -1 << endl;
        else cout << res << endl;
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
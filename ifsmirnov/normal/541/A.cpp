#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstring>
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

int n, m;
int c[maxn];
int x[maxn], y[maxn], l[maxn], r[maxn], p[maxn];
int len[maxn];
int shr[maxn * 4], k;
const int sz = 1<<20;

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%d%d", &l[i], &r[i]);
        len[i] = r[i] - l[i];
    }
    forn(i, m) {
        scanf("%d%d%d", &x[i], &y[i], &c[i]);
    }
    forn(i, n) {
        shr[k++] = l[i];
        shr[k++] = r[i];
    }
    forn(i, m) {
        shr[k++] = x[i];
        shr[k++] = y[i];
    }
    sort(shr, shr+n*4);
    k = unique(shr, shr+n*4) - shr;

    forn(i, n) {
        l[i] = lower_bound(shr, shr+k, l[i]) - shr;
        r[i] = lower_bound(shr, shr+k, r[i]) - shr;
    }

    forn(i, m) {
        x[i] = lower_bound(shr, shr+k, x[i]) - shr;
        y[i] = lower_bound(shr, shr+k, y[i]) - shr;
    }

}

int rmql[sz*2], rmqp[sz*2];

void addl(int i, int x) {
    i += sz;
    rmql[i] = x;
    for (i /= 2; i; i /= 2) {
        rmql[i] = (len[rmql[i*2]] > len[rmql[i*2+1]] ? rmql[i*2] : rmql[i*2+1]);
    }
}

int getl(int l, int r) {
    l += sz; r += sz;
    int mx = maxn - 1;
    while (l < r) {
        if (l % 2 == 1 && len[mx] < len[rmql[l]]) mx = rmql[l];
        if (r % 2 == 0 && len[mx] < len[rmql[r]]) mx = rmql[r];
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r && len[mx] < len[rmql[r]]) mx = rmql[r];
    return mx;
}

void addp(int i, int x) {
    i += sz;
    rmqp[i] = x;
    for (i /= 2; i; i /= 2) {
        rmqp[i] = (p[rmqp[i*2]] < p[rmqp[i*2+1]] ? rmqp[i*2] : rmqp[i*2+1]);
    }
}

int getp(int l, int r) {
    l += sz; r += sz;
    int mx = maxn - 1;
    while (l < r) {
        if (l % 2 == 1 && p[mx] > p[rmqp[l]]) mx = rmqp[l];
        if (r % 2 == 0 && p[mx] > p[rmqp[r]]) mx = rmqp[r];
        l = (l+1)/2;
        r = (r-1)/2;
    }
    if (l == r && p[mx] > p[rmqp[r]]) mx = rmqp[r];
    return mx;
}

struct Ev {
    int t;
    int type; // -1 -- r of no color, 0 -- no color, 1 - color, 2 -- color r
    int id;
    bool operator<(const Ev& e) const {
        if (t != e.t) return t > e.t;
        if (type != e.type) return type < e.type;
        return id < e.id;
    }
};

Ev evs[maxn * 4];
set<pii> avail;

pair<i64, pii> compval(int i, int j) {
    int len = max(0, shr[min(r[i], y[j])] - shr[max(l[i], x[j])]);
    return mp((i64)c[j] * len, mp(i, j));
}

void solve() {
    len[maxn - 1] = -inf;

    pair<i64, pii> best(0, {0,0});

    forn(III, 2) {
        avail.clear();
        forn(i, sz*2) {
            rmql[i] = rmqp[i] = maxn - 1;
        }
        memcpy(p, l, sizeof p);
        p[maxn - 1] = inf;
        forn(i, n) evs[i] = {l[i], 0, i};
        forn(i, m) evs[i+n] = {x[i], 1, i};
        forn(i, n) evs[i+n+m] = {r[i], -1, i};
        forn(i, m) evs[i+n+m+n] = {y[i], 2, i};

//         forn(i, n) cout << shr[l[i]] << " - " << shr[r[i]] << endl;
//         cout << "---" << endl;
//         forn(i, m) cout << shr[x[i]] << " - " << shr[y[i]] << endl;
//         cout << "====" << endl;

        int k = n*2+m*2;
        sort(evs, evs+k);
        forn(i, k) {
            Ev e = evs[i];
            if (e.type == -1) {
                avail.insert(mp(l[e.id], e.id));
//                 cout << "insert " << l[e.id] << " " << e.id << endl;
            } else if (e.type == 0) {
                addl(r[e.id], e.id);
                addp(r[e.id], e.id);
//                 cout << "add to " << r[e.id] << endl;
            } else if (e.type == 1) {
                int id = e.id;
                pair<i64, pii> local_best(0, {0,0});
                // fully inside
//                 cout << "get " << x[id] << " " << y[id] << endl;
                int mlid = getl(x[id], y[id]);
                if (mlid != maxn-1) {
                    local_best = max(local_best, compval(mlid, id));
                }

                // side to the right
//                 cout << "get " << y[id] << " " << sz-1 << endl;
                int rid = getp(y[id], sz - 1);
//                 cout << "got " << rid << endl;
                if (rid != maxn-1) {
                    local_best = max(local_best, compval(rid, id));
                }
                best = max(best, local_best);
            } else {
                int id = e.id;
                // fully inside
                if (!avail.empty()) {
                    best = max(best, compval(avail.begin()->second, id));
                }

//                 cout << id << ": " << local_best.fi << endl;
            }
        }

//         break;

        forn(i, n) {
            l[i] = ::k - l[i] - 1;
            r[i] = ::k - r[i] - 1;
            swap(l[i], r[i]);
        }
        forn(i, m) {
            x[i] = ::k - x[i] - 1;
            y[i] = ::k - y[i] - 1;
            swap(x[i], y[i]);
        }
        reverse(shr, shr+::k);
        forn(i, ::k) shr[i] = -shr[i];
    }
    
    cout << best.fi << endl;
    if (best.fi) {
        cout << best.se.fi + 1 << " " << best.se.se + 1 << endl;
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
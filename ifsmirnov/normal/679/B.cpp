// 777666555444333
// 870183790872090
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef long long i64;
typedef pair<int, i64> pii;
typedef unsigned long long u64;

const int K = 2000000;
pii d1[K];
map<i64, pii> d2;

i64 cb(i64 x) {
    return x*x*x;
}

i64 nxt(i64 x) {
    int i = cbrt(x) + 1;
    while (cb(i) > x) --i;
    return i;
}


pii get(i64 x) {
    if (x == 1) { return {1,1}; }

    if (x < K) {
        if (d1[x].fi) return d1[x];
    } else {
        if (d2.count(x)) return d2[x];
    }

    i64 initialX = x;
    pii best = {0,0};
    forn(III, 150) {
        if (x == 0) break;
        int i = nxt(x);
        i64 rem = x - cb(i);
        pii t = get(rem);
        ++t.fi;
        t.se += cb(i);
        best = max(best, t);
        assert(best.se <= initialX);
        x = cb(i) - 1;
    }

    if (initialX < K) {
        return d1[initialX] = best;
    } else {
        return d2[initialX] = best;
    }
}

i64 score(i64 x) {
    int c = 0;
    while (x) {
        int i = nxt(x);
        x -= cb(i);
//         cerr << i << " " << cb(i) << endl;
        ++c;
    }
    return c;
}

i64 f(i64 x) {
    i64 bv = x;
    i64 best = score(x);
    forn(i, 2000000) {
        --x;
        if (x == 0) break;
        i64 t = score(x);
        if (t > best) best = t, bv = x;
    }
    return bv;
}

int main() {
#ifdef LOCAL
//     freopen("b.in", "r", stdin);
#endif

//     fore(i, 1, 100) {
//         if (f(i) != get(i).se) {
//             cerr << i << ": " << f(i) << ", " << get(i).se << endl;
//         }
//     }

//     auto t = get(8);
//     cerr << t.fi << " " << t.se << endl;

    while (true) {
        i64 x;
        if (!(cin >> x)) break;
        auto t = get(x);
        cout << t.fi << " " << t.se << endl;
        break;
    }
    /*
    int mx = 0;
    int prev = 0;
    int mxp = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (score(i) >= mx) {
            mx = score(i);
            cout << mx << ": " << i << " " << i - prev << endl;
            mxp = max(mxp, i - prev);
            prev = i;
        }
    }
    cerr << "mxp = " << mxp << endl;
    */


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
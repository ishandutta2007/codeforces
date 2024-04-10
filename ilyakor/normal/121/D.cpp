/*
 * Powered by C++Helper v0.001alpha
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int64 inf = (int64)(2e18);

vector<int64> gen() {
    vector<int64> res;
    for (int len = 1; len <= 18; ++len)
        for (int mask = 0; mask < (1 << len); ++mask) {
            int64 cur = 0;
            for (int i = 0; i < len; ++i)
                cur = cur * 10LL + (int64) (((mask >> i) & 1) ? 7 : 4);
            if (cur < 0) cerr << "AAAA\n";
            res.pb(cur);
        }

    sort(all(res));

    return res;
}

vector<int64> l, r;
vector<int64> sl, sr;

int n;

int64 mult(int64 x, int64 y) {
    if (y == 0) return 0;
    if (x == 0) return 0;
    if (x > inf / y + 2LL) return inf;
    int64 res = x * y;
    if (res > inf) res = inf;
    return res;
}

int64 _getL(int ind, int64 x) {
    int64 res = 0;
    for (int i = ind; i < sz(l); ++i) {
        res += l[i] - x;
        res = min(res, inf);
    }
    return res;
}

int64 _getR(int ind, int64 x) {
    int64 res = 0;
    for (int i = 0; i <= ind; ++i) {
        res += x - r[i];
        res = min(res, inf);
    }
    return res;
}

int64 getL(int ind, int64 x) {
    int64 res = sl[ind];
    int64 val = ind >= sz(l) ? 0LL : (l[ind] - x);
    res += mult(val, sz(l) - ind);
    if (res > inf) res = inf;
//    if (res != _getL(ind, x)) { cerr << ind << " " << x << " " << res << " " << _getL(ind, x) << "\n"; while (1); }
    return res;
}

int64 getR(int ind, int64 x) {
    int64 res = sr[ind + 1];
    int64 val = ind == -1 ? 0LL : (x - r[ind]);
    res += mult(val, ind + 1);
    if (res > inf) res = inf;
//    if (res != _getR(ind, x)) {cerr << ind << " " << x << " " << res << " " << _getR(ind, x) << "\n"; while (1);}
    return res;
}

int64 calc(int64 x, int64 y) {
    int il = lower_bound(all(l), x) - l.begin();
    int ir = lower_bound(all(r), y) - r.begin();
    if (ir == sz(r)) --ir;
    while (ir >= 0 && ir < sz(r) && r[ir] > y) --ir;

    int64 res = getL(il, x);
    res += getR(ir, x);

    return min(res, inf);
}

int main() {
    cin >> n;
    l.resize(n);
    r.resize(n);
    int64 k;
    cin >> k;
    int64 M = inf;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        M = min(M, r[i] - l[i]);
    }

    sort(all(l));
    sort(all(r));
    
    sl.resize(sz(l) + 1);
    sl[sz(sl) - 1] = 0;
    for (int i = sz(l) - 1; i >= 0; --i) {
        sl[i] = sl[i + 1];

        int64 d = i == sz(l) - 1 ? 0LL : (l[i + 1] - l[i]);
        d = mult(d, sz(l) - i - 1);
        sl[i] += d;

  //      sl[i] += l[i];
        if (sl[i] > inf) sl[i] = inf;
    }

    sr.resize(sz(r) + 1);
    sr[0] = 0;
    for (int i = 0; i < sz(r); ++i) {
        sr[i + 1] = sr[i];

        int64 d = i == 0 ? 0LL : (r[i] - r[i - 1]);
        d = mult(d, i);
        sr[i + 1] += d;

//        sr[i + 1] += r[i];
        if (sr[i + 1] > inf) sr[i + 1] = inf;
    }

    int64 res = 0;
    
    vector<int64> v = gen();
//    cerr << "start\n";
    for (int i = 0; i < sz(v); ++i) {
        int down = i, up = sz(v);
        while (up - down > 1) {
            int t = (up + down) / 2;
            if (v[t] - v[i] > M) {
                up = t;
                continue;
            }
            if (calc(v[i], v[t]) > k)
                up = t;
            else
                down = t;
        }
        if (calc(v[i], v[i]) > k) up = down;
        res = max(res, (int64) (up - i));
    }

    cout << res << "\n";
    return 0;
}
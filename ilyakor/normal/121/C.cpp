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

vector<int64> gen() {
    vector<int64> res;
    for (int len = 1; len <= 11; ++len)
        for (int mask = 0; mask < (1 << len); ++mask) {
            int64 cur = 0;
            for (int i = 0; i < len; ++i)
                cur = cur * 10LL + (int64) (((mask >> i) & 1) ? 7 : 4);
            res.pb(cur);
        }

    sort(all(res));

    return res;
}

int64 f[40];

vi solve(int n, int k) {
    --k;
    f[0] = 1;
    for (int i = 1; i < 40; ++i)
        f[i] = f[i - 1] * (int64) i;

    if (k >= f[n]) {
        printf("-1\n");
        exit(0);
    }

    vi res;
    vi u(n, 0);
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        while (k >= f[n - i - 1]) ++cur, k -= f[n - i - 1];
        int x = 0;
        while (cur > 0) {
            if (!u[x]) --cur;
            ++x;
        }
        while (u[x]) ++x;
        u[x] = true;
        res.pb(x);
    }
    return res;
}

int main() {
    vector<int64> v = gen();
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < sz(v); ++i)
        if (v[i] < n - 14)
            ++res;
    vi w;
    for (int i = max(n - 14, 1); i <= n; ++i)
        w.pb(i);
    vi p = solve(sz(w), k);
    vi ww(sz(w));
    for (int i = 0; i < sz(w); ++i)
        ww[i] = w[p[i]];
    for (int i = 0; i < sz(w); ++i) {
        int x = max(n - 14, 1) + i;
        if (!binary_search(all(v), (int64)x)) continue;
        if (!binary_search(all(v), (int64)ww[i])) continue;
        ++res;
    }
    cout << res << "\n";
    return 0;
}
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

const int64 inf = (int64)(2E18);

vector<int64> f;

int64 calcR(int64 n, int ind) {
    if (n == 0) return 1;
    if (ind < 0) return 0;
    if (f[ind] > n) return calcR(n, ind - 1);
    return calcR(n, ind - 1) + calcR(n - f[ind], ind - 1);
}

vi v;

int64 d[100][2][2];

int64 go(int ind, int p1, int p2) {
    if (ind >= sz(v)) return 1;
    int64& res = d[ind][p1][p2];
    if (res != -1) return res;
    res = 0;
    res += go(ind + 1, p2, v[ind]);
    if (p1 && !p2) {
        if (!v[ind]) res += go(ind + 1, 1, 1);
        else {
            int t = ind + 1;
            bool ok = false;
            while (t + 1 < sz(v)) {
                if (v[t] == 0 && v[t + 1] == 0) {
                    ok = true;
                    break;
                }
                if (v[t] == 1) break;
                t += 2;
            }
            if (ok) {
                res += go(t + 2, 1, 1);
            }
        }
    }
    return res;
}

int main() {
    f.pb(1);
    f.pb(2);
    while (f[sz(f) - 1] < inf) {
        f.pb(f[sz(f) - 1] + f[sz(f) - 2]);
    }
//    cerr << sz(f) << "\n";

    int nc;
    cin >> nc;
    for (int it = 0; it < nc; ++it) {
        int64 n;
        cin >> n;
//        cerr << calcR(n, sz(f) - 1) << "\n";
        v.clear();
        for (int i = sz(f) - 1; i >= 0; --i) {
            if (f[i] > n) {
                if (sz(v)) v.pb(0);
                continue;
            }
            n -= f[i];
            v.pb(1);
        }
        memset(d, -1, sizeof(d));
        int64 res = go(0, 0, 0);
        cout << res << "\n";
    }
    return 0;
}
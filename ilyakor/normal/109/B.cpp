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

int64 cross(int64 l1, int64 r1, int64 l2, int64 r2) {
    int64 res = min(r1, r2) - max(l1, l2) + 1;
    return max(res, 0LL);
}

int main()
{
    vector<int64> v;
    for (int i = 1; i <= 12; ++i) {
        for (int mask = 0; mask < (1 << i); ++mask) {
            int64 x = 0;
            for (int j = 0; j < i; ++j) {
                x *= 10;
                if ((mask >> j) & 1)
                    x += 7;
                else
                    x += 4;
            }
            v.pb(x);
        }
    }
    
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    int64 pl, pr, vl, vr;
    int k;
    cin >> pl >> pr >> vl >> vr >> k;

    double rx = 0.0, ry = 0.0;

    ry = pr - pl + 1;
    ry *= vr - vl + 1;

    for (int i = 0; i < sz(v); ++i) {
        if (v[i] > max(pr, vr)) break;

        int64 r1 = v[i];
        int64 l1 = i ? (v[i - 1] + 1): 0;
        int64 r2 = v[i + k] - 1;
        int64 l2 = (i + k) ? v[i + k - 1] : 0;

        rx += cross(l1, r1, pl, pr) * cross(l2, r2, vl, vr);
        rx += cross(l2, r2, pl, pr) * cross(l1, r1, vl, vr);
        if (k == 1) rx -= cross(r1, l2, pl, pr) * cross(r1, l2, vl, vr);

    }
    
    /*cerr << rx << "\n";
    rx = 0;
    for (int i = pl; i <= pr; ++i)
        for (int j = vl; j <= vr; ++j) {
            int x = min(i, j), y = max(i, j);
            int cnt = 0;
            for (int t = x; t <= y; ++t)
                if (binary_search(all(v), (int64)t))
                    ++cnt;
            if (cnt == k) ++rx;
        }

    cerr << rx << "\n";*/

    if (ry == 0.0) ry = 1.0;
    printf("%.20lf\n", rx / ry);

    return 0;
}
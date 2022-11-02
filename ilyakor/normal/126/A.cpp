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

#define y1 y89742974398
#define y2 y24957849080

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main() {
    int64 t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    int64 r1 = 0, r2 = x2;
    if (t1 == t2) r1 = x1, r2 = x2;
    for (int64 y1 = 0; y1 <= x1; ++y1) {
        if (t2 == t0) continue;
        int64 tmp = y1 * (t0 - t1);
        int64 t = t2 - t0;
        tmp = tmp / t + (tmp % t ? 1LL : 0LL);

        if (tmp > x2) continue;
        if (tmp < 0) continue;

        int64 y2 = tmp;

        if (y1 == 0 && y2 == 0) continue;

        int64 p1 = y1 * (t1 - t0) + y2 * (t2 - t0);
        int64 q1 = y1 + y2;

        int64 p2 = r1 * (t1 - t0) + r2 * (t2 - t0);
        int64 q2 = r1 + r2;

        if (p1 * q2 < p2 * q1) {
            r1 = y1, r2 = y2;
            continue;
        }

        if (p1 * q2 > p2 * q1) continue;

        if (y1 + y2 > r1 + r2)
            r1 = y1, r2 = y2;
    }

    cout << r1 << " " << r2 << "\n";
    return 0;
}
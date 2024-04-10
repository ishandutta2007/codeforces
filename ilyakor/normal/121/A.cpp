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

int64 cross(int64 x1, int64 y1, int64 x2, int64 y2) {
    int64 res = min(y1, y2) - max(x1, x2) + 1;
    return max(0LL, res);
}

int main() {
    int l, r;
    cin >> l >> r;
    vector<int64> v = gen();
    int64 prev = 0;
    int64 res = 0;
    for (int i = 0; i < sz(v); ++i) {
        int64 cur = cross(prev, v[i], l, r);
        //if (cur) cerr << cur << " " << prev << " " << v[i] << "\n";
        cur *= v[i];
        res += cur;
        prev = v[i] + 1;
    }
    cout << res << "\n";
    return 0;
}
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

int calc(int s, int t, int64 m) {
    int x = t / (2 * (m - 1)) - 2;
    x = max(x, 0);
    int64 res = (int64)(1E18);
    for (int k = x; k <= x + 8; ++k) {
        int64 t1 = 2LL * (m - 1) * k + s;
        if (t1 >= t) res = min(res, t1);
        t1 = 2LL * (m - 1) * k - s;
        if (t1 >= t) res = min(res, t1);
    }

    return (int) res;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int s, f, t;
        cin >> s >> f >> t;
        --s, --f;
        int res;
        if (s == f) res = t;
        else res = calc(f, calc(s, t, m), m);
        cout << res << "\n";
    }
    return 0;
}
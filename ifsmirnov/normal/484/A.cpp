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

i64 solve1(i64 l, i64 r) {
    int t = 0;
    i64 mx = 0;
    fore(i, l, r) {
        if (__builtin_popcount(i) > t) {
            t = __builtin_popcount(i);
            mx = i;
        }
    }
    return mx;
}

i64 solve(i64 l, i64 r) {
//     cout << "solve " << l << " " << r << endl;
    int a = 0, b = 0;
    if (!(l & (l+1))) {
//         cout << l << " " << r << ": " << l << endl;
        return l;
    }
    while (l >= (1ll<<a)) ++a;
    while (r >= (1ll<<b)) ++b;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    if (a > b) {
//         cout << l << " " << r << " : " << (1ll<<(a-1)) - 1 << endl;
        return (1ll<<(a-1)) - 1;
    } else {
        i64 t = (1ll<<(a-1)) + solve(l^(1ll<<(a-1)), r^(1ll<<(a-1)));
//         cout << l << " " << r << ": " << t << endl;
        return t;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    i64 l, r;
    forn(i, t) {
        cin >> r >> l;
        cout << solve(l, r) << "\n";
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
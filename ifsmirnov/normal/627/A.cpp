#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
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

int main() {
#ifdef HOME
    freopen("a.in", "r", stdin);
#endif

    i64 s, x;
    cin >> s >> x;
    if (s < x || (s-x) % 2) {
        cout << 0 << endl;
        return 0;
    }
    if (x == 0) {
        cout << 1 << endl;
        return 0;
    }
    bool eq = s == x;
    i64 d = (s-x) / 2;
//     cerr << "d = " << d << endl;
    i64 r = 1;
//     string res = "";
    while (x || d) {
        if (d&1) {
            if (x&1) {
                r = 0;
                break;
            }
//             res += '1';
        } else if (x&1) {
            r *= 2;
//             res += '1';
        } else {
//             res += '0';
        }
        d /= 2;
        x /= 2;
    }
//     reverse(all(res));
//     cout << res << endl;

    if (eq) r -= 2;
    cout << r << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
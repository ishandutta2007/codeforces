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
const int maxn = 200500;
const int mod = 1000000007;

int r, g;
int d[maxn], b[maxn];

void solve() {
    d[0] = b[0] = 1;
    int s = 0;
    for (int i = 1;; ++i) {
        i64 res = 0;
        bool ok = false;
        s += i;
//         cout << "i = " << i << endl;
//         cout << "s-i = " << s-i << endl;
        for (int j = min(r, s); j >= 0; --j) {
//             cout << s-j-i << " " << g << endl;
            if (b[j] && s-j-i <= g) {
//                 cout << "add " << j << endl;
                res += d[j];
            }
            if (j >= i && b[j-i]) {
                b[j] = 1;
                d[j] += d[j-i];
                if (d[j] >= mod) d[j] -= mod;
            }
            if (b[j] && s-j <= g) ok = true;
        }
//         cout << "res = " << res << endl;
//         forn(j, s+1) cout << d[j] << " "; cout << endl;
        if (!ok) {
//             cout << "i = " << i << endl;
            cout << res%mod << endl;
            return;
        }
    }
}

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    cin >> r >> g;
    solve();


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
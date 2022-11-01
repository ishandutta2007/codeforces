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

int n;
int a[maxn];

void scan() {
//     n = 50;
//     forn(i, n) a[i] = rand()%100 + 1;
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
}

int solved() {
    int mx = 0;
    forn(i, n) forn(j, n) if (a[i] > a[j]) {
        mx = max(mx, a[i] % a[j]);
    }
    return mx;
}

int solve() {
    sort(a, a+n);
    n = unique(a, a+n) - a;
    a[n] = 1000000000;
    int res = 0;
    ford(i, n) {
        int x = a[i];
        if (x <= res) {
            break;
        }
        int pos = i + 1;
        int cv = x * 2;
        while (pos < n) {
            pos = upper_bound(a+pos, a+n, cv-1) - a - 1;
//             cout << cv << " " << pos << endl;
            int rem = a[pos] - (cv - x);
            if (rem != x) {
                res = max(res, rem);
            }
            ++pos;
            cv += x;
        }
    }
//     return res;
    printf("%d\n", res);
    return 1;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

//     srand(time(NULL));
    scan();
    solve();

//     while (1) {
//         scan();
//         int t = solved();
//         int a = solve();
//         int t1 = solved();
//         if (t != t1) {
//             cout << "sdfdsf" << endl;
//         }
//         if (t != a) {
//             cout << n << endl;
//             forn(i, n) cout << ::a[i] << " "; cout << endl;
//             break;
//         }
//     }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
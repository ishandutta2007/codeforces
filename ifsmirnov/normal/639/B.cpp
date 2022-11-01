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

void fail() {
    printf("-1\n");
    exit(0);
}

int main() {
#ifdef HOME
    freopen("b.in", "r", stdin);
#endif

    int n, d, h;
    scanf("%d%d%d", &n, &d, &h);
    if (d < h || d > h*2) fail();
    if (n < d + 1) fail();
    if (d == 1 && h == 1) {
        if (n == 2) {
            printf("1 2\n");
            return 0;
        } else {
            fail();
        }
    }
    if (d == 2 && h == 1) {
        for (int i = 2; i <= n; ++i) {
            printf("%d %d\n", 1, i);
        }
        return 0;
    }

    int t = 2;
    forn(i, h) {
        printf("%d %d\n", t-1, t);
        ++t;
    }
    int pr = 1;
    forn(i, d-h) {
        printf("%d %d\n", pr, t);
        pr = t;
        ++t;
    }

    while (t <= n) {
        printf("%d %d\n", 2, t);
        ++t;
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
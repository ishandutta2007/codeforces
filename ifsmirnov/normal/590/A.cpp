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

int med(int x, int y, int z) {
    return x + y + z > 1;
}

vi go(const vi& a) {
    int n = a.size();
    vi r(n);
    r[0] = a[0];
    r[n-1] = a[n-1];
    for (int i = 1; i < n-1; ++i) {
        r[i] = med(a[i-1], a[i], a[i+1]);
    }
    return r;
}

int dumb(vi a) {
    int c = 0;
    while (true) {
        if (a == go(a)) {
            for (auto x: a) cout << x << " ";
            cout << endl;
            return c;
        }
        ++c;
        a = go(a);
    }
}

int sol(vi a) {
    int n = a.size();
    vi b(a);
    int mx = 0;
    int ls = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1] || i+1 == n || a[i] == a[i+1]) {
            mx = max(mx, (i-ls)/2);
            if (a[ls] == a[i]) {
                for (int j = ls; j <= i; ++j) b[j] = a[i];
            } else {
                assert((i-ls)%2 == 1);
                for (int j = ls, k = i; j < k; ++j, --k) {
                    b[j] = a[ls];
                    b[k] = a[i];
                }
            }
            ls = i;
        }
    }
    printf("%d\n", mx);
    forn(i, n) printf("%d ", b[i]); printf("\n");
    return mx;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    vi a(n);
    forn(i, n) scanf("%d", &a[i]);
//     cout << dumb(a) << endl;

    sol(a);

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
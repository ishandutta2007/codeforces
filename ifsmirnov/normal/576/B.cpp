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

const int maxn = 100500;

int n;
int a[maxn];
int b[maxn];
vi l, r;
int r1 = -1, r2;

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]), --a[i];
    forn(v, n) if (a[v] == v) {
        printf("YES\n");
        forn(i, n) if (i != v) {
            printf("%d %d\n", i+1, v+1);
        }
        return 0;
    }
    forn(v, n) if (!b[v]) {
        int p = a[v];
        if (a[p] == v && r1 == -1) {
            r1 = v;
            r2 = p;
            b[p] = b[v] = 1;
            continue;
        }
        int i = 0;
        l.pb(v);
        b[v] = 1;
        do {
            b[p] = 1;
            (i?l:r).pb(p);
            i = !i;
            p = a[p];
        } while (p != v);
        if (i == 0) {
            printf("NO\n");
            return 0;
        }
    }

    if (r1 == -1) {
        printf("NO\n");
        return 0;
    }

    assert(l.size() == r.size());
    assert(l.size() * 2 + 2 == size_t(n));
    printf("YES\n");
    printf("%d %d\n", r1+1, r2+1);
    forn(i, n/2-1) {
        printf("%d %d\n", r1+1, l[i]+1);
        printf("%d %d\n", r2+1, r[i]+1);
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
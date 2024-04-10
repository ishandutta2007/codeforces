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

const int maxn = 400500;

int n;
int a[maxn];
int p[maxn];
int c[maxn];
int b[maxn];
int per;

int pi() {
    forn(i, n) if (i) {
        p[i] = p[i-1];
        while (p[i] && a[i] != a[p[i]]) {
            p[i] = p[p[i]-1];
        }
        p[i] += a[i] == a[p[i]];
    }
    if (n % (n - p[n-1]) == 0) return n - p[n-1];
    return n;
}

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) a[i+n] = a[i];
}

int was[maxn];

i64 solve(int g) {
    assert(n % g == 0);

    int l = n/g;

    forn(i, g) c[i] = 0;

    int r = 0;
    forn(i, n) {
        c[r] = max(c[r], a[i]);
        if (++r == g) r = 0;
    }

    forn(i, n) {
        b[i] = b[i+n] = a[i] == c[r];
        if (++r == g) r = 0;
    }

    if (count(b, b+n, 1) == n) {
        forn(i, l) was[i*g] = 1;
        return (i64)n * (l-1);
    }

    int fp = 0;
    while (b[fp] == 1) ++fp;
    i64 res = 0;

    int cnt = 0;
    forn(i, n+1) {
        if (i == n || b[fp+i] == 0) {
            cnt = 0;
        } else {
            ++cnt;
            res += cnt / g;
            was[cnt/g*g] = 1;
        }
    }

    assert(cnt == 0);
    return res;
}

int mu(int n) {
    int res = 1;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            if (n%(i*i) == 0) return 0;
            res *= -1;
            n  /= i;
        }
    }
    return n == 1 ? res : -res;
}

i64 ss[maxn];
int mm[maxn];

void solve() {
    for (int i = 1; i <= n; ++i) mm[i] = mu(i);

    i64 res = 0;
    for (int g = 1; g < n; ++g) if (n % g == 0 && !was[g]) {
        i64 t = solve(g);
        ss[g] = t;
//         cout << g << ": " << t << endl;
        res += ss[g];
    }

//     cout << "----" << endl;
// 
//     for (int len = 1; len < n; ++len) {
//         i64 tres = ss[len];
//         for (int k = 2; len * k < n; ++k) {
//             tres += ss[len*k] * mm[k];
//         }
//         cout << len << ": " << tres << endl;
//         res += tres;
//     }

    cout << res << endl;
}


int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
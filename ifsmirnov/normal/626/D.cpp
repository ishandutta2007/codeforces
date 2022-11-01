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
typedef long double ld;
const int maxn = 10350;

int n;
int a[maxn];
i64 diff[maxn];
i64 dd[maxn]; // diff + diff
i64 s[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
}

void solve() {
    forn(i, n) forn(j, n) if (a[i] > a[j]) ++diff[a[i]-a[j]];
    forn(i, 5050) forn(j, 5050) dd[i+j] += diff[i] * diff[j];
    forn(i, 10300) {
        s[i] = dd[i];
        if (i) s[i] += s[i-1];
    }

    ld res = 0;
    forn(i, 10040) if (i) res += (ld) diff[i] * s[i-1];

    ld cn2 = n * (n-1) / 2;
    forn(i, 3) res /= cn2;

    cout.precision(20);
    cout << fixed;
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
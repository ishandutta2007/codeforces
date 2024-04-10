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
int b[maxn], c[maxn];
int d[maxn];
int dd;
char buf[maxn];
int f[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
}

void run() {
    dd = 0;
    forn(i, n) {
        int x = a[i];
        int p = lower_bound(d, d+dd, x) - d;
        assert(p <= dd);
        if (p == dd) {
            ++dd;
        }
        d[p] = x;
        b[i] = p+1;
    }
}

void solve() {
    run();
    forn(i, n) c[i] = b[i], a[i] = -a[i];
    reverse(a, a+n);
    run();
    reverse(b, b+n);

    int mx = *max_element(b, b+n);
//     cout<< "mx = " << mx << endl;
//     forn(i, n) { cout << b[i] << " "; } cout << endl;
//     cout << endl;
//     forn(i, n) cout << c[i] << " "; cout << endl;

    forn(i, n) if (b[i] + c[i] == mx + 1) {
        ++f[b[i]];
        buf[i] = '2';
    } else {
        buf[i] = '1';
    }
    forn(i, n) if (b[i] + c[i] == mx + 1 && f[b[i]] == 1) {
        buf[i] = '3';
    }
    printf("%s\n", buf);
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
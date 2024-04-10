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
const int mod = 1000000007;
const int maxn = 1050;

int c[maxn][maxn];
int n;
int a[maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    c[0][0] = 1;
    forn(i, maxn) if (i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }

    cin >> n;
    forn(i, n) cin >> a[i];
    int res = 1, s = 0;
    forn(i, n) {
        res = (i64)res * c[s + a[i] - 1][a[i] - 1] % mod;
        s += a[i];
    }
    cout << res << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
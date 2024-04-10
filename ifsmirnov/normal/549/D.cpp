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

const int maxn = 105;

int n, m;
int a[maxn][maxn];
int s[maxn][maxn];
int d[maxn][maxn];
int res;
char buf[maxn];

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%s", buf);
        forn(j, m) a[n-i-1][m-j-1] = buf[j] == 'W' ? 1 : -1;
    }
}

void solve() {
    forn(i, n) forn(j, m) {
        s[i][j] = 0;
        if (i) s[i][j] += s[i-1][j];
        if (j) s[i][j] += s[i][j-1];
        if (i&&j) s[i][j] -= s[i-1][j-1];
        if (s[i][j] != a[i][j]) {
            s[i][j] += (a[i][j] - s[i][j]);
            ++res;
        }
    }
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
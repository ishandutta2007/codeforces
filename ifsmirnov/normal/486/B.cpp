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
int a[maxn][maxn], b[maxn][maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    forn(i, n) forn(j, m) scanf("%d", &b[i][j]);
    forn(i, n) forn(j, m) a[i][j] = 1;
    forn(i, n) forn(j, m) if (b[i][j] == 0) {
        forn(k, n) a[k][j] = 0;
        forn(k, m) a[i][k] = 0;
    }
    forn(i, n) forn(j, m) {
        int t = 0;
        forn(k, n) t |= a[k][j];
        forn(k, m) t |= a[i][k];
        if (t != b[i][j]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES" << endl;
    forn(i, n) {
        forn(j, m) cout << a[i][j] << " ";
        cout << endl;
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
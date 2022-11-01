#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstring>
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
int mod;
const int maxn = 510;

int n, m;
int a[maxn];
int f[maxn][maxn*2], g[maxn][maxn*2];
int B;

int add(int x, int y) { return (x+y)%mod; }

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m >> B >> mod;
    forn(i, n) cin >> a[i];
    f[0][0] = 1;
    forn(i, m) {
        forn(p, n) {
            forn(b, B+1) {
                g[p][b+a[p]] = add(f[p][b], g[p][b+a[p]]);
                f[p+1][b] = add(f[p+1][b], f[p][b]);
            }
        }
        memcpy(f, g, sizeof f);
        memset(g, 0, sizeof g);
    }

    int s = 0;
    forn(p, n) forn(i, B+1) s = add(s, f[p][i]);
    cout << s << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
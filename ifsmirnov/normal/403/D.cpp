#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <cstdlib>
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
int madd(int x, int y) { return (x+y)%mod; }
int mmul(int x, int y) { return (i64)x*y%mod; }
void relax(int& x, int y) { x = madd(x, y); }

const int maxn = 1010;
int d[50][maxn][maxn];
int sl[50][maxn];

int c[1200][1200];
int f[1200];

void compc() {
    c[0][0] = 1;
    forn(n, 1200) {
        c[n][0] = c[n][n] = 1;
        fore(k, 1, n-1) c[n][k] = madd(c[n-1][k], c[n-1][k-1]);
    }

    f[0] = 1;
    forn(i, 1200) if (i) f[i] = mmul(f[i-1], i);
}

void compd(int N) {
    d[0][0][0] = 1;
    int cnt = 0;
    int h = 0;
    forn(k, maxn) {
        int rcnt = cnt;
        forn(r, N) {
            forn(l, N-r+3) {
                if (d[k][r][l] == 0) continue;
                h += d[k][r][l];
                ++cnt;
                relax(d[k][r+1][l], d[k][r][l]);
                relax(d[k+1][r+1][l+r+1], d[k][r][l]);
                relax(sl[k+1][l+r+1], d[k][r][l]);
            }
        }
        if (rcnt == cnt) {
            cerr << "h = " << h << endl;
            cerr << "cnt = " << cnt << endl;
            cerr << "break at " << k << endl;
            break;
        }
    }
}

map<pii, int> q;

int get(int n, int k) {
    if (k >=45) return 0;
    if (q.count(mp(n, k))) return q[mp(n, k)];
    int res = 0;
    forn(l, n+1) {
        int fp = n-l;
        relax(res, mmul(sl[k][l], c[fp+k][k]));
    }
    return q[mp(n, k)] = mmul(res, f[k]);
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
#endif

    compc();
    compd(1003);

    int t;
    scanf("%d", &t);
    forn(i, t) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", get(n, k));
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
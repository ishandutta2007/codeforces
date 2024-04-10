#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define se second
#define fi first
#define fpos dfszf
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 2030;
const int mod =1000000007;
int add(int x, int y) { x += y; return x >= mod ? x - mod : x; }
int mul(int x, int y) { return (i64)x*y%mod; }
int sub(int x, int y) { return add(x, (mod-y)%mod); }

int c[maxn][maxn];
int f[maxn];

void compcf() {
    c[0][0] = 1;
    fore(n, 1, maxn-1) {
        c[n][0] = c[n][n] = 1;
        fore(k, 1, n-1)
            c[n][k] = add(c[n-1][k], c[n-1][k-1]);
    }
    f[0] = 1;
    fore(n, 1, maxn-1)
        f[n] = mul(f[n-1], n);
}

int n;
int a[maxn];
int b[maxn];
vi fpos, fval;

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]), --a[i];
}

void solve() {
    compcf();
    forn(i, n) {
        if (a[i] == -2)
            fpos.pb(i);
        else
            b[a[i]] = 1;
    }
    forn(i, n) if (!b[i])
        fval.pb(i);

    int n = fpos.size();
    int k = 0;
    forn(i, n)
        k += binary_search(all(fval), fpos[i]);

    int res = f[n];
    fore(i, 1, k) {
        int t = mul(c[k][i], f[n-i]);
//         cout << "i = " << i << ", t = " << t << endl;
        if (i%2 == 1)
            res = sub(res, t);
        else
            res = add(res, t);
    }

    cout << res << endl;
}

int main()
{
//     freopen("input.txt", "r", stdin);

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}
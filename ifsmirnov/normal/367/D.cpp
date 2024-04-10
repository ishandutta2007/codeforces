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
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 100500;

int n, m, D;
int a[maxn];
int d[1<<20][21];
int cnt[22];
int f[1<<20][21];

void scan() {
    scanf("%d%d%d", &n, &m, &D);
    forn(i, m) {
        int k;
        scanf("%d", &k);
        forn(j, k) {
            int x;
            scanf("%d", &x);
            a[x-1] = i;
        }
    }
}

string bin(int x) {
    string s;
    forn(i, m) {
        s += '0' + x%2;
        x /= 2;
    }
    return s;
}

void solve() {
    forn(i, D-1) ++cnt[a[i]];
    for (int i = D-1; i < n; ++i) {
        ++cnt[a[i]];
        int mask = 0;
        forn(j, m) if (cnt[j]) mask |= (1<<j);
        ++d[mask][0];
//         cout << bin(mask) << endl;
//         forn(j, m) cout << cnt[a[j]] << " "; cout << endl;

        --cnt[a[i-D+1]];
    }
    ford(i, 1<<m) forn(j, m) {
        d[i][j+1] += d[i][j];
        if (i&(1<<j)) d[i^(1<<j)][j] += d[i][j];
    }

//     forn(i, 1<<m) cout << bin(i) << ": " << d[i][m] << endl;
//     cout << endl;

    forn(i, 1<<m) if (i) {
        f[i][0] = d[i][m];
        forn(j, m) {
            if (i&(1<<j)) {
                f[i][j] -= f[i^(1<<j)][j];
            }
            f[i][j+1] += f[i][j];
        }
    }

//     forn(i, 1<<m) cout << bin(i) << ": " << f[i][m] << endl;

    int minres = (1<<m)-1;
    forn(i, 1<<m) if (i && abs(f[i][m]) == n-D+1) {
//         cout << __builtin_popcount(i) << endl;
        if (__builtin_popcount(i) < __builtin_popcount(minres))
            minres = i;
    }

    cout << __builtin_popcount(minres) << endl;
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}
#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int S = 1000 + 13;
const int N = 100 + 13;
const int mod = 1000 * 1000 * 1000 + 7;

int n, s;
int xs[N], ys[N];
int c[S][S];
int z[N][S];

int main()
{

    cin >> n;

    forn(i, n)
        cin >> xs[i], s += xs[i];

    forn(i, n)
        cin >> ys[i];

    c[0][0] = 1;
    for1(i, s)
        forn(j, i + 1)
            c[i][j] = ((j == 0 ? 0 : c[i - 1][j - 1]) + c[i - 1][j]) % mod;

    z[0][0] = 1;
    forn(i, n)
        forn(j, s + 1)
        {
            if (z[i][j] == 0)
                continue;

            int cur = j + xs[i];
            int fin = min(cur, ys[i]) + 1;

            forn(here, fin)
            {
                z[i + 1][cur - here] = (z[i + 1][cur - here] + z[i][j] * 1LL * c[cur][here]) % mod;
            }
        }

    int ans = z[n][0];

    int fp = 1;

    int curs = s;

    forn(i, n)
        fp = (fp * 1LL * c[curs][xs[i]]) % mod, curs -= xs[i];

    cout << (fp * 1LL * ans) % mod << endl;

//  cerr << "fp = " << fp << " ans = " << ans << endl;
        
    return 0;
}
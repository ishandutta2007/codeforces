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

const int N = 2000 + 13;

int n;
pt s[N];
int xs[2 * N], sz;
map <int, int> tonum;
vector <pt> g[2 * N];
int z[2 * N][2 * N];

int solve (int lf, int rg)
{
    int &res = z[lf][rg];

    if (res != -1)
        return res;

    if (lf == rg)
        return 0;

    res = solve(lf + 1, rg);

    int dx = 0;

    forn(i, sz(g[lf]))
    {
        int to = g[lf][i].ft;

        if (to == rg)
        {
            dx = 1;
            continue;
        }

        if (to < rg)
            res = max(res, solve(lf, to) + solve(to, rg));
    }

    return res += dx;
}

void write (int lf, int rg)
{
    int dx = 0, id = -1;

    forn(i, sz(g[lf]))
        if (g[lf][i].ft == rg)
        {
            dx = 1;
            id = g[lf][i].sc;
            break;
        }

    if (id != -1)
        printf("%d ", id + 1);

    forn(i, sz(g[lf]))
    {
        int to = g[lf][i].ft;

        if (to >= rg)
            continue;

        if (z[lf][rg] == z[lf][to] + z[to][rg] + dx)
        {
            write(lf, to);
            write(to, rg);
            return;
        }
    }

    if (z[lf][rg] == z[lf + 1][rg] + dx)
        write(lf + 1, rg);
}


int main()
{

    cin >> n;

    forn(i, n) 
    {
        int x, r;
        scanf("%d%d", &x, &r);

        s[i] = mp(x - r, x + r);

        xs[sz++] = x - r;
        xs[sz++] = x + r;
    }

    sort(xs, xs + sz);

    sz = int(unique(xs, xs + sz) - xs);

    forn(i, sz)
        tonum[xs[i]] = i;

    forn(i, n)
        g[tonum[s[i].ft]].pb(mp(tonum[s[i].sc], i));

    memset(z, -1, sizeof(z));

    int t = solve(0, sz - 1);

    cout << t << endl;

    write(0, sz - 1);

    return 0;
}
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

const int N = 32000 + 13;

int a, b, n;
vector <li> g[N];

int z[N][35];

int solve (int a, int b)
{
    int &res = z[a][b];

    if (res != -1)
        return res;

    if (a == 1)
    {
        if (sz(g[a + 1]) > b && g[a + 1][b] >= n)
            return res = 2;

        if (solve(a + 1, b) == 0)
            return res = 1;

        int t = solve(a, b + 1);

        if (t == 1)
            return res = 0;
        else if (t == 0)
            return res = 1;
        else
            return res = 2;
    }

    if (b == 1 && sz(g[a]) > b + 1 && g[a][b + 1] >= n)
        return res = 1 - (n - a) % 2;
    
    if (sz(g[a + 1]) > b && g[a + 1][b] < n && solve(a + 1, b) == 0)
        return res = 1;

    if (sz(g[a]) > b + 1 && g[a][b + 1] < n && solve(a, b + 1) == 0)
        return res = 1;

    return res = 0;
}

int main()
{

    forn(i, 35)
        g[1].push_back(1);

    for (int i = 2; i < N; i++)
    {
        li cur = 1;

        while (cur < INF)
            g[i].pb(cur), cur *= i;

        g[i].pb(cur);
    }       

    cin >> a >> b >> n; 

    memset(z, -1, sizeof(z));

    int t = solve(a, b);

    if (t == 0)
        cout << "Stas";
    else if (t == 1)
        cout << "Masha";
    else
        cout << "Missing";

    cout << endl;

    return 0;
}
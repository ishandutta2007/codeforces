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

const int N = 1000 * 1000 + 13;

string s1, s2;
li h[N];

li deg[N];

int main()
{

    deg[0] = 1;

    for1(i, N - 1)
        deg[i] = deg[i - 1] * 1009LL;

    cin >> s1 >> s2;

    li h2 = 0;

    forn(i, sz(s2))
        h2 = h2 + s2[i] * deg[i];

    h2 *= 1009LL;

    h[0] = s1[0];

    for1(i, sz(s1) - 1)
        h[i] = h[i - 1] + s1[i] * deg[i];

    vector <int> ans;       

    forn(i, sz(s1))
    {
        li curh = h[sz(s1) - 1];

        curh -= h[i];

        curh += (i == 0 ? 0 : h[i - 1] * 1009LL);

        if (curh == h2)
            ans.pb(i);      
    }

    cout << sz(ans) << endl;

    forn(i, sz(ans))
        printf("%d ", ans[i] + 1);

    cout << endl;

    return 0;
}
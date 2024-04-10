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
const li INF = li(1e18);

int val, n;
string s;
vector <pt> v;
int pos = 0;

pt expr ()
{
    int k = 1, type = 0;

    string cur = "";

    while (s[pos] >= '0' && s[pos] <= '9')
        cur.pb(s[pos++]);

    if (!cur.empty())
        k = atoi(cur.c_str()), pos++;

    if (s[pos] == 'a')
        type = 1;

    pos += 3;

    return mp(k, type); 
}

void unary ()
{
    while (pos < n)
    {
        char c = s[pos++];
                
        pt t = expr();

        if (c == '-')
            t.ft *= -1;

        v.pb(t);
    }
}

int main()
{

    cin >> val;

    cin >> s;

    s = "+" + s;

    n = sz(s);

    unary();

    sort(all(v));

    li ans = 0;

    forn(i, sz(v))
    {
        if (v[i].sc == 0)
            val++;

        ans += v[i].ft * val;

        if (v[i].sc == 1)
            val++;
    }

    cout << ans << endl;

    return 0;
}
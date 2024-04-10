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

const int N = 1000 + 13;

int n;
pt a[N];
string s[N];

bool add (string &s)
{
    bool bad = true;

    forn(i, sz(s))
        if (s[i] != '1')
        {
            bad = false;
            break;
        }

    if (bad)
        return false;

    int yk = sz(s) - 1;

    while (s[yk] == '1')
        s[yk] = '0', yk--;

    s[yk] = '1';

    return true;
}

int main()
{

    cin >> n;

    forn(i, n)
    {
        cin >> a[i].ft, a[i].sc = i;
    }

    sort(a, a + n);

    string cur = "";

    forn(i, a[0].ft)
        cur.pb('0');

    s[a[0].sc] = cur;

    for1(i, n - 1)
    {
        if (!add(cur))
        {
            cout << "NO" << endl;
            return 0;
        }

        while (sz(cur) < a[i].ft)
            cur.pb('0');

        s[a[i].sc] = cur;
    }

    cout << "YES" << endl;

    forn(i, n)
        puts(s[i].c_str());

    return 0;
}
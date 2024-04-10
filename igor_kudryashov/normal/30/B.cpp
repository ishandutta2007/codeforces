#pragma comment (linker, "/stack:16000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <stack>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define X first
#define Y second
#define ft first
#define sc second

template <typename X> inline X abs (const X& a) { return a < 0 ? -a : a; }
template <typename X> inline X sqr (const X& a) { return a * a; }

typedef long long li;
typedef pair <int, int> pt;
typedef long double ld;
typedef pair <ld, ld> ptd;
const int INF = int (1e9);
const int NMAX = int (1e4);
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool Correct (int d, int m, int y)
{
    if (m < 1 || m > 12)
        return false;

    if (d == 29 && m == 2 && y % 4 == 0)
        return true;

    if (d < 1 || d > month[m - 1])
        return false;

    return true;
}

bool check (int d, int m, int y, int day, int mon, int year)
{
    if (d == 29 && m == 2 && y % 4 == 0)
    {
        y += 18;
        d = 1;
        m = 3;
    } else
        y += 18;

    if (y > year)
        return false;

    if (y < year)
        return true;

    if (m > mon)
        return false;

    if (m < mon)
        return true;

    if (d > day)
        return false;

    return true;
}

int main()
{ 

    int day, mon, year;
    int td, tm, ty;

    scanf("%d.%d.%d", &day, &mon, &year);

    scanf("%d.%d.%d", &td, &tm, &ty);

    vector <int> v;

    v.push_back(td);
    v.push_back(tm);
    v.push_back(ty);

    vector <int> perm;
    forn(i, 3)
        perm.push_back(i);

    do
    {
        if (Correct(v[perm[0]], v[perm[1]], v[perm[2]]) && check(v[perm[0]], v[perm[1]], v[perm[2]], day, mon, year))
        {
            cout << "YES" << endl;
            return 0;
        }
    } while (next_permutation(all(perm)));

    cout << "NO" << endl;

    return 0;
}
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

bool pw (li a, int b, li res)
{
    li cur = 1;

    forn(i, b)
    {
        cur *= a;

        if (abs(cur) > abs(res))
            return false;
    }

    return cur == res;
}

int main()
{ 

    li a, b;
    int n;

    cin >> a >> b >> n;

    if (a == 0)
    {
        if (b != 0)
            cout << "No solution" << endl;
        else
            cout << 1 << endl;

        return 0;
    }

    if (abs(b) % abs(a) != 0)
    {
        cout << "No solution" << endl;
        return 0;
    }

    li res = b / a;

    for (li i = -1000; i <= 1000; i++)
        if (pw(i, n, res))
        {
            cout << i << endl;
            return 0;
        }

    cout << "No solution" << endl;

    return 0;
}
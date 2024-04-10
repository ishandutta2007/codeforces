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

const int N = 500 + 13;

int n, m;
pt p[N];
int seg[N];
vector <int> ans;
bool used[N];

bool go (int fir)
{
    ans.clear();

    vector <int> lens;

    for (int i = fir; i < n; i += 2)
    {
        int cur = 0;

        int prev = (i - 1 + n) % n;

        if (p[i].first != p[prev].first && p[i].second != p[prev].second)
            return false;
    
        cur += abs(p[i].first - p[prev].first) + abs(p[i].second - p[prev].second);

        int next = (i + 1) % n;

        if (p[i].first != p[next].first && p[i].second != p[next].second)
            return false;

        cur += abs(p[i].first - p[next].first) + abs(p[i].second - p[next].second);

        lens.push_back(cur);
    }

    memset(used, 0, sizeof(used));

    int it = 0;

    forn(i, n)
    {
        if ((i & 1) == fir)
        {
            bool ok = false;

            forn(j, m)
                if (!used[j] && seg[j] == lens[it])
                {
                    ok = true;
                    ans.push_back(j);
                    used[j] = true;
                    it++;
                    break;
                }

            if (!ok)
                return false;
        } else
            ans.push_back(-2);
    }

    return true;
}

int main()
{ 

    cin >> n >> m;

    forn(i, n)
        scanf("%d%d", &p[i].ft, &p[i].sc);

    forn(i, m)
        scanf("%d", &seg[i]);

    if (go(0))
    {
        cout << "YES" << endl;

        forn(i, sz(ans))
            printf("%d ", ans[i] + 1);

        return 0;
    }

    if (go(1))
    {
        cout << "YES" << endl;

        forn(i, sz(ans))
            printf("%d ", ans[i] + 1);

        return 0;
    }

    cout << "NO" << endl;

    return 0;
}
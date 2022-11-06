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

int n, heal, rej;
pt perdam[N];
bool used[N];
int num[N];

int main()
{

    cin >> n >> heal >> rej;

    forn(i, n)
    {
        cin >> perdam[i].ft >> perdam[i].sc;
        num[i] = i;
    }

    vector <pt> ans;
    int curt = 0;
    int curh = heal;
    int curdam = 0;

    while (true)
    {
        int maxv = 0, id = -1;

        forn(i, n)
            if (perdam[i].ft * heal >= curh * 100)
            {
                if (maxv < perdam[i].sc)
                    maxv = perdam[i].sc, id = i;
            }

        if (id != -1)
        {
            ans.pb(mp(curt, num[id]));
            curdam += perdam[id].sc;
            swap(perdam[id], perdam[n - 1]);
            swap(num[id], num[n - 1]);
            n--;
        }
    
        if (id == -1 && curdam <= rej)
        {
            cout << "NO" << endl;
            return 0;
        }            

        curh -= curdam;

        curh = min(heal, curh + rej);

        curt++;

        if (curh <= 0)
            break;
    }

    cout << "YES" << endl;

    cout << curt << ' ' << sz(ans) << endl;

    forn(i, sz(ans))
        printf("%d %d\n", ans[i].ft, ans[i].sc + 1);

    return 0;
}
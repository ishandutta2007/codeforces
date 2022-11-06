#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
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

int cntF, cntE, cntS;
ld rF, rE, rS;
int damF, damE;
bool used[13][2];
ptd segmsS[13];
ld ans;
ptd canTake[100];
int szcanTake;

inline bool cmp (const ptd& a, const ptd& b)
{
    if (abs(a.ft - b.ft) > EPS)
        return a.ft > b.ft;
        
    return a.sc > b.sc + EPS;
}

ld d[23][23];
ld maxSumE[100][23];

ld calcAns ()
{
    assert(szcanTake >= cntF + cntE);

    forn(i, szcanTake + 1)
        forn(j, cntE + 1)
            maxSumE[i][j] = 0.0;
            
    ford(i, szcanTake)
        forn(j, cntE + 1)
        {
            maxSumE[i][j] = max(maxSumE[i][j], maxSumE[i + 1][j]);
                
            if (j > 0)
                maxSumE[i][j] = max(maxSumE[i][j], maxSumE[i + 1][j - 1] + canTake[i].sc);
        }

    forn(i, cntF + 1)
        forn(j, cntE + 1)
            d[i][j] = 0.0;
            
    forn(i, cntF + 1)
        forn(j, cntE + 1)
        {
            if (i < cntF)
                d[i + 1][j] = max(d[i + 1][j], d[i][j] + canTake[i + j].ft);
                
            if (j < cntE)
                d[i][j + 1] = max(d[i][j + 1], d[i][j] + canTake[i + j].sc);
                
            if (i == cntF)
                d[cntF][cntE] = max(d[cntF][cntE], d[i][j] + maxSumE[i + j][cntE - j]);
        }
        
    return d[cntF][cntE];
}

inline ptd cross (const ptd& a, const ptd& b)
{
    return mp(max(a.ft, b.ft), min(a.sc, b.sc));
}

inline ld calcDamage (int x, ld r, ld dam)
{
    ld dx = sqrt(sqr(r) - 1.0);
    ptd curSegm = mp(x - dx, x + dx);
    if (curSegm.sc - curSegm.ft < EPS) return 0.0;
    
    ld res = (curSegm.sc - curSegm.ft) * dam;
    
    forn(i, 13)
    {
        int cnt = int(used[i][0]) + int(used[i][1]);
        if (cnt == 0) continue;
        
        ptd cur = cross(curSegm, segmsS[i]);
        ld len = max(ld(0), cur.sc - cur.ft);
        
        res += cnt * len * dam;
    }
    
    return res;
}

void solve ()
{
    szcanTake = 0;
    
    forn(i, 13)
    {
        if (!used[i][1])
            canTake[szcanTake++] = mp(calcDamage(i, rF, damF), calcDamage(i, rE, damE));
            
        if (!used[i][0])
            canTake[szcanTake++] = canTake[szcanTake - 1];
    }
            
    sort(canTake, canTake + szcanTake, cmp);
        
    ans = max(ans, calcAns());
}

void go (int col, int row, int remS)
{
    if (col == 13 && remS == 0)
        solve();
        
    if (remS > 2 * (13 - col))
        return;
        
    go(col + 1, 0, remS);
    
    if (remS > 0)
    {
        used[col][row] = true;
        
        if (row == 0)
            go(col, row + 1, remS - 1);
        else
            go(col + 1, 0, remS - 1);
            
        used[col][row] = false;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> cntF >> cntE >> cntS;
    cin >> rF >> rE >> rS;
    cin >> damF >> damE;
    
    /*if (cntF == 0 && cntE == 0)
    {
        cout << setprecision(10) << fixed;
        cout << ld(0) << endl;
        return 0;
    }*/
    
    forn(i, 13)
        segmsS[i] = mp(i - sqrt(sqr(rS) - 1.0), i + sqrt(sqr(rS) - 1.0));
    
    go(0, 0, cntS);
    
    cout << setprecision(10) << fixed;
    cout << ans << endl;    

    return 0;
}
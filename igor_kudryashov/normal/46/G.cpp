#pragma comment(linker, "/stack:64000000")
#define _SECURE_SCL 0
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

int n;

const int N = 200 * 1000 + 13;

vector <pair <int, pt> > v;
int xs[N], ys[N];

void gen ()
{
    for (int i = 1; 2 * i * i < N; i++)
        for (int j = 0; j <= i; j++)
            xs[sqr(i) + sqr(j)] = i, ys[sqr(i) + sqr(j)] = j;
            
    for (int i = 0; sz(v) < n + 1; i++)
        if (xs[i] != 0 || ys[i] != 0)
            v.pb(mp(i, mp(xs[i], ys[i])));
}

void norm ()
{
    sort(all(v));
    
    assert(sz(v) == n + 1);

    li sum = 0;
    int sx = 0, sy = 0;
    
    forn(i, n + 1)
        sx += v[i].sc.ft, sy += v[i].sc.sc, sum += v[i].ft;
        
    for (int i = sz(v) - 1; i >= 0; i--)
        if (((sum - v[i].ft) & 1) == 0)
        {
            sum -= v[i].ft;
            sx -= v[i].sc.ft, sy -= v[i].sc.sc;
            swap(v[i], v.back());
            v.pop_back();
            sort(all(v));
            break;
        }

    if (sx & 1)
    {
        forn(i, n)
            if ((v[i].sc.ft + v[i].sc.sc) & 1)
            {
                swap(v[i].sc.ft, v[i].sc.sc);
                break;
            }
    }
}

const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};

inline li len (const pt& a)
{
    return abs(a.ft * 1LL * a.ft + a.sc * 1LL * a.sc);
}

pt operator + (const pt& a, const pt& b)
{
    return mp(a.ft + b.ft, a.sc + b.sc);
}

void orient ()
{
    pt sum = mp(0, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        pt best = v[i].sc;
        
        forn(k, 2)
        {
            forn(j, 4)
            {
                pt cur = v[i].sc;
                
                cur.ft *= dx[j];
                cur.sc *= dy[j];
                
                if (len(sum + cur) < len(sum + best))
                    best = cur;
            }
            
            swap(v[i].sc.ft, v[i].sc.sc);
        }
        
        v[i].sc = best;
        
        sum = sum + best;
    }
    
    assert(len(sum) == 0);
}

inline ld ang (const pt& a)
{
    return atan2(ld(a.sc), ld(a.ft));
}

inline bool cmp (const int& i, const int& j)
{
    return ang(v[i].sc) + EPS < ang(v[j].sc);
}

int main()
{
    
    cin >> n;
    
    gen();
    
    norm();
    
    orient();
    
    vector <int> perm;

    forn(i, n)
        perm.pb(i);
        
    sort(all(perm), cmp);
    
//  forn(i, n)
//      cerr << v[perm[i]].sc.ft << ' ' << v[perm[i]].sc.sc << endl;
//  cerr << endl;
    
    cout << "YES" << endl;
    
    int curx = 0, cury = 0;
    
    forn(idx, sz(perm))
    {
        int i = perm[idx];
    
        curx += v[i].sc.ft, cury += v[i].sc.sc;
        
        printf("%d %d\n", curx, cury);
    }   

    return 0;
}
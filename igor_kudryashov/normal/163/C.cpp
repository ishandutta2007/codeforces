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

const int N = 400 * 1000 + 3;

int n;
int len, v1, v2;
vector <ptd> angs;
vector <ld> xs;
int cnt[N];
ld ans[N];

inline bool cmpLess (const ld& a, const ld& b) { return a + EPS < b; }
inline bool cmpEq (const ld& a, const ld& b) { return abs(a - b) < EPS; }

void add (ld lf, ld rg)
{
    if (lf < -EPS)
    {
        angs.pb(mp(lf + 2.0 * PI, 2.0 * PI));
        angs.pb(mp(0.0, rg));
        
        xs.pb(lf + 2.0 * PI);
        xs.pb(2.0 * PI);
        xs.pb(0.0);
        xs.pb(rg);
    
    } else
    {
        angs.pb(mp(lf, rg));
        xs.pb(lf);
        xs.pb(rg);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> len >> v1 >> v2;
    
    ld d = ld(v1) * ld(len) / ld(v1 + v2);
    assert(d < ld(len) + EPS);
    
    ld dalp = (ld(len) - d) / ld(len) * PI;
    //ld dalp = d / len * PI;
    
    forn(i, n)
    {
        int curpos;
        scanf("%d", &curpos);
        
        ld curang = ld(curpos) / ld(len) * PI;
        
        /*if (curpos <= len)
            curang = ld(curpos) / ld(len) * PI;
        else
            curang = PI + ld(curpos - len) / ld(len) * PI;*/
            
        add(curang - dalp, curang);
    }
    
    xs.pb(ld(0));
    xs.pb(2.0 * PI);
    sort(all(xs), cmpLess);
    xs.erase(unique(all(xs), cmpEq), xs.end());
    
    /*forn(i, sz(xs))
        cerr << xs[i] << ' ';
    cerr << endl;*/
    
    forn(i, sz(angs))
    {
        int idxlf = int(lower_bound(all(xs), angs[i].ft, cmpLess) - xs.begin());
        int idxrg = int(lower_bound(all(xs), angs[i].sc, cmpLess) - xs.begin());
        
        cnt[idxlf]++;
        cnt[idxrg]--;
    }
    
    int curCnt = 0;
    
    forn(i, sz(xs) - 1)
    {
        curCnt += cnt[i];
        ans[curCnt] += (xs[i + 1] - xs[i]) / (2.0 * PI);
    }
    
    forn(i, n + 1)
        printf("%.20lf\n", double(ans[i]));

    return 0;
}
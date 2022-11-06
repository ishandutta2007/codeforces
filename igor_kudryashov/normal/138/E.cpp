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

const int N = 100 * 1000 + 13;
const int K = 500 + 13;

int n;
char s[N];
int k, L, R;
int c[K], lf[K], rg[K];
vector <int> occ[26 + 3];
int cntGood, okRules[N];
int ptr[26];

void dec (char c, int rg)
{
    if (ptr[int(c)] < rg) return;

    int lfidx = (ptr[int(c)] - rg - 1 >= 0 ? occ[c][ptr[int(c)] - rg - 1] : -1);
    int rgidx = occ[c][ptr[int(c)] - rg] - (rg == 0);
    
    for (int i = lfidx + 1; i <= rgidx; i++)
    {
        okRules[i]--;
        if (okRules[i] == R)
            cntGood++;
        else if (okRules[i] == L - 1)
            cntGood--;
    }
}

void inc (char c, int lf)
{
    if (lf == 0) return;
    if (ptr[int(c)] + 1 < lf) return;
    
    int lfidx = (ptr[int(c)] - lf >= 0 ? occ[c][ptr[int(c)] - lf] : -1);
    int rgidx = occ[c][ptr[int(c)] - lf + 1] - (lf == 1);
    
    for (int i = lfidx + 1; i <= rgidx; i++)
    {
        okRules[i]++;
        if (okRules[i] == L)
            cntGood++;
        else if (okRules[i] == R + 1)
            cntGood--;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    n = strlen(s);
    forn(i, n)
        s[i] -= 'a';
    
    forn(i, n)
        occ[int(s[i])].pb(i);
    
    scanf("%d %d %d\n", &k, &L, &R);
    
    forn(i, k)
        scanf("%c %d %d\n", &c[i], &lf[i], &rg[i]), c[i] -= 'a';
        
    li ans = 0;
    memset(ptr, -1, sizeof(ptr));
        
    forn(i, n)
    {
        char curc = s[i];
        ptr[int(curc)]++;
        
        forn(j, k)
            if ((curc == c[j] && lf[j] <= 1 && 1 <= rg[j]) || (curc != c[j] && lf[j] == 0))
                okRules[i]++;
                
        if (L <= okRules[i] && okRules[i] <= R)
            cntGood++;
            
        forn(j, k)
        {
            if (curc != c[j]) continue;
            
            inc(curc, lf[j]);
            dec(curc, rg[j]);
        }
        
        /*cerr << "good = " << cntGood << ", ";
        forn(j, i + 1) cerr << okRules[j] << ' ';
        cerr << endl;*/
        
        ans += cntGood;     
    }
    
    cout << ans << endl;

    return 0;
}
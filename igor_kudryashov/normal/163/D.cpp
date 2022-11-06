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

const li INF64 = li(4e18);

const int N = 1000 + 3;
const int M = 300 * 1000 + 3;

int n;
pair <li, int> valDeg[N];
li V;
int divs[M];
int szdivs;
int SQRT, pow13;

void go (int pos, int val)
{
    if (pos == n)
    {
        divs[szdivs++] = val;
        return;
    }

    go(pos + 1, val);
    
    forn(i, valDeg[pos].sc)
    {
        if (val * 1LL * valDeg[pos].ft > SQRT)
            return;
            
        val *= valDeg[pos].ft;
        go(pos + 1, val);
    }
}

struct answer
{
    li ans, a, b, c;
    answer (li ans, li a, li b, li c) : ans(ans), a(a), b(b), c(c) {}
    answer() {}
};
vector <answer> v;

void solve ()
{
    szdivs = 0;
    SQRT = int(sqrt(ld(V)) + EPS);
    pow13 = int(pow(ld(V), ld(1) / ld(3)) + EPS);
    
    go(0, 1);
    
    sort(divs, divs + szdivs);
    
    /*cerr << V << endl;
    forn(i, szdivs)
        cerr << divs[i] << ' ';
    cerr << endl;*/
    
    int last = 0;
    while (last < szdivs && divs[last] <= pow13) last++;
    
    li bestAns = INF64;
    int ansa, ansb;
    li ansc;
    
    for (int i = last - 1; i >= 0; i--)
    {
        int a = divs[i];
        int maxB = int(sqrt(ld(V / a)) + EPS);
        int idx = int(lower_bound(divs, divs + szdivs, maxB) - divs);
        if (idx == szdivs) idx--;
        
        while (idx >= 0)
        {
            int b = divs[idx];
            
            if ((V / a) % b != 0)
            {
                idx--;
                continue;
            }
            
            li c = V / a / b;
            
            li cur = ((a * 1LL * b + b * c + c * a) << 1);
            
            if (cur < bestAns)
                bestAns = cur, ansa = a, ansb = b, ansc = c;
                
            break;
        }
    }
    
    /*if (ansa * 1LL * ansb * ansc != V)
    {
        forn(i, n)
            cout << valDeg[i].ft << ' ' << valDeg[i].sc << ", ";
        cout << V << endl;
    }*/
    
    //assert(ansa * 1LL * ansb * ansc == V);
    
    //v.pb(answer(bestAns, ansa, ansb, ansc));
    printf("%I64d %d %d %I64d\n", bestAns, ansa, ansb, ansc);
}

void read ()
{
    scanf("%d", &n);
    
    V = 1;
    
    forn(i, n)
    {
        scanf("%I64d%d", &valDeg[i].ft, &valDeg[i].sc);
        
        forn(j, valDeg[i].sc)
            V *= valDeg[i].ft;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
        read();
        solve();
    }
    
    //forn(i, sz(v))
    //  cout << v[i].ans << ' ' << v[i].a << ' ' << v[i].b << ' ' << v[i].c << endl;

    return 0;
}
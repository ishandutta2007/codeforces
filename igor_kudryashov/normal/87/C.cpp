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

int n;
int gr[N];

int calc (int n)
{   
    int& res = gr[n];
    
    if (res != -1)
        return res;
        
    set <int> s;
        
    for (int leng = 2; leng * leng <= 2 * n; leng++)
    {   
        if ((2 * n + leng - leng * leng) % (2 * leng) != 0)
            continue;
            
        int a1 = (2 * n + leng - leng * leng) / (2 * leng);
        int x = 0;
        
        for (int i = a1; i < a1 + leng; i++)
            x ^= calc(i);
            
        s.insert(x);
    }
    
    vector <int> v(all(s));
    v.pb(-1);
    
    forn(i, sz(v))
        if (v[i] != i)
            return res = i;
            
    throw;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    memset(gr, -1, sizeof(gr));
    
    int g = calc(n);
    
    if (g == 0)
    {
        puts("-1");
        return 0;
    }
    
    for (int i = 2; i * i <= 2 * n; i++)
    {
        if ((2 * n + i - i * i) % (2 * i) != 0)
            continue;
            
        int a1 = (2 * n + i - i * i) / (2 * i);
        
        int gg = 0;
        
        for (int j = a1; j < a1 + i; j++)
            gg ^= gr[j];
            
        if (gg == 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
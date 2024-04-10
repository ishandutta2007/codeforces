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

const int N = 4 * 100 * 1000 + 3;

char buf[N];
vector <pair <string, string> > v;
string s;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(buf);
    s = string(buf);
    
    int idx = s.find('.');
    
    if (!(idx > 0 && idx < sz(s) - 1 && idx <= 8))
    {
        puts("NO");
        return 0;
    }
    
    string name = s.substr(0, idx);
    
    for (int i = idx + 1; i < sz(s); i++)
    {
        int st = i;
        while (i < sz(s) && s[i] != '.')
            i++;
            
        if (i == sz(s) - 1)
        {
            puts("NO");
            return 0;
        }
            
        if (i == sz(s))
        {
            if (i - st < 1 || i - st > 3)
            {
                puts("NO");
                return 0;
            }
            
            v.pb(mp(name, s.substr(st)));
            break;
        }
            
        if (i - st < 2 || i - st > 11)
        {
            puts("NO");
            return 0;
        }
        
        int len = min(3, i - st - 1);
        
        v.pb(mp(name, s.substr(st, len)));
        name = s.substr(st + len, i - st - len);
    }
    
    puts("YES");
    
    forn(i, sz(v))
        printf("%s.%s\n", v[i].ft.c_str(), v[i].sc.c_str());
    
    return 0;
}
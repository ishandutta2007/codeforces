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

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int n;
    cin >> n;
    map <string, pt> var;
    
    forn(iter, n)
    {
        string s1, s2, s3;
        cin >> s1 >> s2;
        
        if (sz(s1) == 6)
        {
            int cnta = 0, cnts = 0;
            string name;
            
            forn(i, sz(s2))
                if (s2[i] == '&')
                {
                    assert(cnts == 0 && name.empty());
                    cnta++;
                } else if (s2[i] == '*')
                    cnts++;
                else
                {
                    name.pb(s2[i]);
                    assert(cnts == 0);
                }
                    
            if (name != "void" && name != "errtype")
            {
                pt res = mp(1, 0);
            
                if (var.count(name))
                {
                    res = var[name];
                    res.sc = res.sc + cnts - cnta;
                }
                    
                if (res.ft == 1 || res.sc < 0)
                    puts("errtype");
                else
                    printf("%s\n", ("void" + string(res.sc, '*')).c_str());
            
            } else
            {
                pt res = mp(1, 0);
                
                if (name == "void")
                    res.ft = 0;
                else
                    res.ft = 1;
                    
                res.sc = cnts - cnta;
                    
                if (res.ft == 1 || res.sc < 0)
                    puts("errtype");
                else
                    printf("%s\n", ("void" + string(res.sc, '*')).c_str());
            }               
        
        } else
        {
            string s3;
            cin >> s3;

            int cnta = 0, cnts = 0;
            string name;
            
            forn(i, sz(s2))
                if (s2[i] == '&')
                {
                    assert(cnts == 0 && name.empty());
                    cnta++;
                } else if (s2[i] == '*')
                    cnts++;
                else
                {
                    name.pb(s2[i]);
                    assert(cnts == 0);
                }
        
            pt res = mp(1, 0);

            if (name == "void")
                res = mp(0, cnts - cnta);
            else if (var.count(name))
            {
                res = var[name];
                res.sc = res.sc + cnts - cnta;
            }
            
            if (res.ft == 1 || res.sc < 0)
                res = mp(1, 0);
                
            var[s3] = res;
        }
    }

    return 0;
}
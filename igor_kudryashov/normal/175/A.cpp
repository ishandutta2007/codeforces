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

bool bad (string s)
{
    if (s.empty())
        return true;

    if (sz(s) > 7)
        return true;
        
    if (sz(s) > 1 && s[0] == '0')
        return true;
        
    return false;
}

int toInt (string s)
{
    int res = 0, deg = 1;
    
    ford(i, sz(s))
        res += (s[i] - '0') * deg, deg *= 10;
        
    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    string s;
    cin >> s;
    
    int ans = -1;
    
    for1(i, sz(s))
        for (int j = i + 1; j < sz(s); j++)
        {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, j - i);
            string s3 = s.substr(j);
            
            if (bad(s1) || bad(s2) || bad(s3))
                continue;
                
            int v1 = toInt(s1), v2 = toInt(s2), v3 = toInt(s3);
            
            if (v1 > 1000 * 1000 || v2 > 1000 * 1000 || v3 > 1000 * 1000)
                continue;
            
            ans = max(ans, v1 + v2 + v3);
        }
        
    cout << ans << endl;

    return 0;
}
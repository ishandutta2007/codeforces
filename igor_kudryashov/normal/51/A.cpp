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
set <string> s;

int main()
{
    
    cin >> n;
    
    forn(i, n)
    {
        string s1, s2, tmp;
        cin >> s1 >> s2 >> tmp;
        
        vector <string> v;
        
        {
            string cur = "";
            cur.pb(s1[0]), cur.pb(s1[1]), cur.pb(s2[0]), cur.pb(s2[1]);
            v.pb(cur);
        }
        {
            string cur = "";
            cur.pb(s1[1]), cur.pb(s2[1]), cur.pb(s1[0]), cur.pb(s2[0]);
            v.pb(cur);
        }   
        {
            string cur = "";
            cur.pb(s2[1]), cur.pb(s2[0]), cur.pb(s1[1]), cur.pb(s1[0]);
            v.pb(cur);
        }
        {
            string cur = "";
            cur.pb(s2[0]), cur.pb(s1[0]), cur.pb(s2[1]), cur.pb(s1[1]);
            v.pb(cur);
        }
        
        sort(all(v));
        
        s.insert(v[0]);
    }
    
    cout << sz(s) << endl;

    return 0;
}
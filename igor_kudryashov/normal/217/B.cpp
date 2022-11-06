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

int n, r;

int gcd (int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

inline int calc (int a)
{
    int res = 0, steps = 0;
    int b = r;
    bool fir = true;
    
    while (a != 1 && b != 1)
    {
        if (a < b) swap(a, b);
        //cerr << a << ' ' << b << endl;
        
        int cnt = a / b;
        
        steps += cnt;
        res += cnt - 1;
        
        a %= b;
    }
    
    if (a > b) swap(a, b);
    //cerr << a << ' ' << b << endl;
    
    res += max(0, b - 2);
    steps += b;
    
    //cerr << "res = " << res << ' ' << steps << endl << endl;
    
    if (steps != n) res = INF;
    
    return res;
}

inline string getS (int a, int b)
{
    string ans = "";
    
    while (a != 1 || b != 1)
    {
        if (a > b)
            ans.pb('T'), a -= b;
        else if (b > a)
            ans.pb('B'), b -= a;
        else
            throw;
    }
    
    ans.pb('T');
    reverse(all(ans));
    
    if (sz(ans) > 2 && ans[sz(ans) - 1] == ans[sz(ans) - 2])
        ans[sz(ans) - 1] = (ans[sz(ans) - 1] == 'T' ? 'B' : 'T');
    
    return ans;
}

inline int getCnt (const string& s)
{
    int res = 0;
    
    forn(i, sz(s) - 1)
        if (s[i] == s[i + 1])
            res++;
            
    return res;
}

int calc (string s)
{
    int a = 0, b = 1;
    
    forn(i, sz(s) - 1)
        if (s[i] == 'T')
            a += b;
        else if (s[i] == 'B')
            b += a;
        else
            throw;
            
    return a + b;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n >> r;
    
    if (r == 1)
    {
        if (n == 1)
        {
            puts("0");
            puts("T");
        }
        else
            puts("IMPOSSIBLE");
            
        return 0;
    }
    
    int ansVal = INF, ansS = -1;
    
    for (int i = 1; i < r; i++)
        if (gcd(r, i) == 1)
        {
            int cur = calc(i);
            if (ansVal > cur)
                ansVal = cur, ansS = i;
        }
        
    if (ansS == -1)
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    
    string s1 = getS(r, ansS);
    string s2 = getS(ansS, r);
    
    if (getCnt(s1) > getCnt(s2))
        swap(s1, s2);
        
    assert(getCnt(s1) == ansVal);
    assert(calc(s1) == r);
        
    cout << getCnt(s1) << endl;
    puts(s1.c_str());
    
    return 0;
}
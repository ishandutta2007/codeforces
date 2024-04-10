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

const int LEN = 10000 + 13;
const int N = 2500 * 4 + 13;

int n, k;
char buf[LEN];
string s[N];

inline bool checkAAAA ()
{
    for (int i = 0; i < n; i += 4)
    {
        forn(j, 4)
            if (s[i] != s[i + j])
                return false;
    }
    
    return true;
}

inline bool checkAABB ()
{
    for (int i = 0; i < n; i += 4)
    {
        if (s[i] != s[i + 1])
            return false;
            
        if (s[i + 2] != s[i + 3])
            return false;
    }
    
    return true;
}

inline bool checkABAB ()
{
    for (int i = 0; i < n; i += 4)
    {
        if (s[i] != s[i + 2])
            return false;
            
        if (s[i + 1] != s[i + 3])
            return false;
    }
    
    return true;
}

inline bool checkABBA ()
{
    for (int i = 0; i < n; i += 4)
    {
        if (s[i] != s[i + 3])
            return false;
            
        if (s[i + 1] != s[i + 2])
            return false;
    }
    
    return true;
}

inline bool vowel (char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

inline int getPos (const string& s, int k)
{
    int cnt = 0;
    
    ford(i, sz(s))
    {
        if (vowel(s[i]))
            cnt++;
            
        if (cnt == k)
            return i;
    }
    
    return -1;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d%d\n", &n, &k);
    n *= 4;
    
    forn(i, n)
    {
        gets(buf);
        string cur = string(buf);
        
        int idx = getPos(cur, k);
        
        if (idx == -1)
        {
            puts("NO");
            return 0;
        }
        
        s[i] = cur.substr(idx);
    }
    
    if (checkAAAA())
    {
        puts("aaaa");
        return 0;
    }
    
    if (checkAABB())
    {
        puts("aabb");
        return 0;
    }
    
    if (checkABAB())
    {
        puts("abab");
        return 0;
    }
    
    if (checkABBA())
    {
        puts("abba");
        return 0;
    }
    
    puts("NO");

    return 0;
}
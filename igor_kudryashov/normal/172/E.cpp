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

const int LEN = 10 * 1000 * 1000 + 3;
const int N = 200 + 13;

int m;
char s[LEN];
char buf[LEN];
vector <pair <li, bool> > a;
int cnt[N], ptr, sz;
li hs[N];

inline li getHash (const string& s)
{
    li res = 0;
    
    ford(i, sz(s))
        res = (res * 1009LL + (s[i] - '0'));
        
    return res;
}

int solve ()
{
    string cur = "";
    int len = strlen(buf);
    buf[len++] = ' ';
    sz = ptr = 0;
    
    forn(i, len)
        if (buf[i] == ' ')
        {
            hs[sz] = getHash(cur);
            cnt[sz] = 0;
            sz++;
            cur = "";
        
        } else
            cur.pb(buf[i]);
            
    int ans = 0;
    
    forn(i, sz(a))
        if (a[i].sc)
        {
            if (ptr < sz && hs[ptr] == a[i].ft)
                ptr++;
                
            if (ptr > 0 && hs[ptr - 1] == a[i].ft)
            {
                cnt[ptr - 1]++;
                ans += (ptr == sz);
            }
                
        } else
        {
            if (ptr > 0 && hs[ptr - 1] == a[i].ft)
                cnt[ptr - 1]--;
                
            if (ptr > 0 && cnt[ptr - 1] == 0)
                ptr--;
        }
        
    return ans;
}

void parse ()
{
    string cur = "";
    int len = strlen(s);
    
    forn(i, len)
    {
        cur.pb(s[i]);
        
        if (s[i] == '>')
        {
            if (cur[sz(cur) - 2] == '/')
            {
                li h = getHash(cur.substr(1, sz(cur) - 3));
                a.pb(mp(h, true));
                a.pb(mp(h, false));             
            
            } else if (cur[1] == '/')
            {
                li h = getHash(cur.substr(2, sz(cur) - 3));
                a.pb(mp(h, false));
            } else
            {
                li h = getHash(cur.substr(1, sz(cur) - 2));
                a.pb(mp(h, true));
            }
            
            cur = "";
        }
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    parse();
    
    scanf("%d\n", &m);
    
    forn(i, m)
    {
        gets(buf);
        printf("%d\n", solve());
    }

    return 0;
}
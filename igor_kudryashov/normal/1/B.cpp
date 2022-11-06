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

const int N = 100 + 13;
const int MAX = 1000 * 1000 + 13;

int n;
char buf[N];
string numToStr[MAX];
map <string, int> strToNum;
int sz = 0;
char f[N];
int deg[10];

int getNum (string s)
{
    int n = sz(s);
    
    int res = 0;// = (s[0] - 'A' + 1) * deg[n - 1];
    
    for (int i = n - 1; i >= 0; i--)
        res += (s[i] - 'A' + 1) * deg[n - 1 - i];
        
    return res;
}

string getStr (int n)
{
    vector <int> res;
    
    while (n > 0)
        if (n % 26 == 0)
        {
            res.pb(26);
            n /= 26;
            n--;
        } else
        {
            res.pb(n % 26);
            n /= 26;
        }
        
    string s;
    
    forn(i, sz(res))
        s.pb('A' + res[i] - 1);
            
    reverse(all(s));
    
    return s;
}

int main()
{
    
    deg[0] = 1;
    for1(i, 9)
        deg[i] = deg[i - 1] * 26;
        
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
        scanf("%s", buf);
    
        int idx = -1;
        int n = strlen(buf);
        
        forn(i, n)
            if (isdigit(buf[i]))
            {
                idx = i;
                break;
            }
            
        int pos = -1;
            
        for (int i = idx; i < n; i++)
            if (isalpha(buf[i]))
            {
                pos = i;
                break;
            }
            
        if (pos == -1)
        {
            string t;
            forn(i, n)
                t.pb(buf[i]);
        
            printf("R%dC%d\n", atoi(t.substr(idx).c_str()), getNum(t.substr(0, idx)));
        
        } else
        {
            int r, c;
            sscanf(buf, "R%dC%d", &r, &c);
            
            printf("%s%d\n", getStr(c).c_str(), r);     
        }       
    }

    return 0;
}
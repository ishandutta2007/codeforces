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

const int N = 100 * 1000 + 13;

int n;
char s[N];

string s1, s2;
int maxv = -1;

vector <int> cnt;
vector <int> cnt1, cnt2;

int solve (vector <int> cnt1, vector <int> cnt2, string& t1, string& t2, int f)
{
    t1.clear();
    t2.clear();

    int ans = 0;

    if (cnt1[f] > 0 && cnt2[10 - f] > 0)
    {
        t1.pb(f + '0');
        t2.pb((10 - f) + '0');
        cnt1[f]--;
        cnt2[10 - f]--;
        
        ans++;
        
        forn(i, 10)
        {
            int maxv = min(cnt1[i], cnt2[9 - i]);
            
            t1 += string(maxv, i + '0');
            t2 += string(maxv, (9 - i) + '0');
            
            cnt1[i] -= maxv;
            cnt2[9 - i] -= maxv;
            
            ans += maxv;
        }
    }
        
    reverse(all(t1));
    reverse(all(t2));
    
    int maxv = min(cnt1[0], cnt2[0]);
    t1 += string(maxv, '0');
    t2 += string(maxv, '0');
    cnt1[0] -= maxv;
    cnt2[0] -= maxv;
    ans += maxv;
    
    reverse(all(t1));
    reverse(all(t2));
    
    forn(i, 10)
        while (cnt1[i] > 0)
        {
            t1.pb(i + '0');
            cnt1[i]--;
        }
    
    forn(i, 10)
        while (cnt2[i] > 0)
        {
            t2.pb(i + '0');
            cnt2[i]--;
        }
        
    reverse(all(t1));
    reverse(all(t2));
        
    return ans;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    n = strlen(s);
    
    forn(i, 10)
        cnt.pb(0);
    
    forn(i, n)
        cnt[s[i] - '0']++;
        
    for1(i, 9)
    {
        cnt1 = cnt2 = cnt;
        string t1, t2;
        
        int curv = solve(cnt1, cnt2, t1, t2, i);
        
        if (curv <= maxv)
            continue;
            
        s1 = t1;
        s2 = t2;
        maxv = curv;
    }
        
    puts(s1.c_str());
    puts(s2.c_str());

    return 0;
}
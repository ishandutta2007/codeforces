#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 + 13;

int b, d;
string a, c;

inline bool read()
{
    if (scanf("%d%d", &b, &d) != 2)
        return false;
        
    assert(cin >> a);
    assert(cin >> c);
    
    return true;
}

int len[N];

void prepare ()
{
    string cur = "";
    forn(i, 105) forn(j, sz(a)) cur.pb(a[j]);
    
    forn(start, sz(a))
    {
        int ptr = start;
        
        forn(i, sz(c))
        {
            while (ptr < sz(cur) && cur[ptr] != c[i]) ptr++;
            if (ptr == sz(cur)) { ptr = INF; break; }
            ptr++;
        }
        
        if (ptr == INF) len[start] = INF; else len[start] = ptr - start;
    }   
    
    //forn(i, sz(a)) cerr << len[i] << ' '; cerr << endl;
}

int idx[N];
li lens[N];
int szlens;

bool can (int mid)
{
    li mustCnt = d * 1LL * mid;
    
    forn(i, sz(a)) idx[i] = -1;
    
    szlens = 0;
    
    int curRem = 0;
    
    li needLen = 0;
    bool calcLen = false;
    
    for (li i = 1; i <= mustCnt; i++)
    {
        if (idx[curRem] != -1)
        {
            int cntTail = idx[curRem], cntPer = szlens - idx[curRem];
            li lenTail = 0; forn(j, cntTail) lenTail += lens[j];
            li lenPer = 0; fore(j, cntTail, szlens - 1) lenPer += lens[j];
            
            li needPer = (mustCnt - cntTail) / cntPer;
            
            needLen += lenTail + lenPer * needPer;
            
            int after = (mustCnt - cntTail) % cntPer;
            
            //cerr << cntTail << ' ' << cntPer << endl;
            
            fore(j, cntTail, cntTail + after - 1) needLen += lens[j];
            
            calcLen = true;
            break;
        
        } else
        {
            idx[curRem] = szlens;
            lens[szlens++] = len[curRem];
            curRem = (curRem + len[curRem]) % sz(a);
        }
    }
    
    if (!calcLen) forn(i, szlens) needLen += lens[i];
    
    //cerr << mid << ' ' << mustCnt << ' ' << needLen << ' ' << sz(a) * 1LL * b << endl;
    
    return needLen <= sz(a) * 1LL * b;
}

inline void solve()
{
    prepare();
    
    if (len[0] > INF / 2)
    {
        puts("0");
        return;
    }
    
    int lf = 1, rg = INF;
    
    while (lf != rg)
    {
        int mid = (lf + rg + 1) >> 1;
        
        if (can(mid))
            lf = mid;
        else
            rg = mid - 1;
    }
    
    if (can(lf)) cout << lf << endl;
    else cout << 0 << endl;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
    return 0;
}
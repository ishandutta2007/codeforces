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

int cnt[100];

map <string, int> num;

string sz[100];

int get (int idx)
{
    forn(i, 10)
        if (cnt[idx + i] > 0)
            return idx + i;
        else if (cnt[idx - i] > 0)
            return idx - i;
            
    throw;
}

int main()
{
    
    num["S"] = 10;
    num["M"] = 11;
    num["L"] = 12;
    num["XL"] = 13;
    num["XXL"] = 14;
    
    sz[10] = "S";
    sz[11] = "M";
    sz[12] = "L";
    sz[13] = "XL";
    sz[14] = "XXL";
                
    forn(i, 5)
        cin >> cnt[10 + i];
        
    int k;
    cin >> k;
        
    forn(i, k)
    {
        string man;
        cin >> man;
        
        int idx = get(num[man]);
        
        assert(cnt[idx] > 0);
        
        cnt[idx]--;
        
        printf("%s\n", sz[idx].c_str());
    }   

    return 0;
}
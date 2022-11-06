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

int n;
map <string, int> score;

string verdict (int cnt, int total)
{
    if (2 * cnt < total) return "noob";
    
    if (2 * cnt >= total && 5 * (total - cnt) > total) return "random";
    
    if (5 * cnt >= 4 * total && 10 * (total - cnt) > total) return "average";
    
    if (10 * cnt >= 9 * total && 100 * (total - cnt) > total) return "hardcore";
    
    if (100 * cnt >= 99 * total) return "pro";
    
    throw;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        string name;
        int val;
        cin >> name >> val;
        
        score[name] = max(score[name], val);
    }
    
    vector < pair <string, int> > men;
    
    for (map <string, int> :: iterator it = score.begin(); it != score.end(); it++)
        men.pb(mp(it->ft, it->sc));
        
    cout << sz(men) << endl;
        
    forn(i, sz(men))
    {
        int cnt = 0;
        forn(j, sz(men))
            if (men[i].sc >= men[j].sc)
                cnt++;
                
        printf("%s ", men[i].ft.c_str());
        
        puts(verdict(cnt, sz(men)).c_str());
    }

    return 0;
}
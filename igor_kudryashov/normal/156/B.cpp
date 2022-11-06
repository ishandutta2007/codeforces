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

int n, m;
char type[N];
int man[N];
int cnt0, cnt1;
int heMurder[N], heIsNot[N];

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d %d\n", &n, &m);
    
    forn(i, n)
    {
        scanf("%c%d\n", &type[i], &man[i]);
        man[i]--;
        
        if (type[i] == '+')
        {
            cnt1++;
            heMurder[man[i]]++;
            
        } else
        {
            cnt0++;
            heIsNot[man[i]]++;
        }
    }
    
    set <int> can;
    
    forn(i, n)
    {
        int willTrue = 0;
        willTrue += heMurder[i];
        willTrue += cnt0 - heIsNot[i];
        
        if (willTrue == m)
            can.insert(i);
    }
    
    //assert(sz(can) >= 1);
    
    forn(i, n)
    {
        if (type[i] == '+')
        {
            if (sz(can) == 1)
            {
                if (man[i] == *can.begin())
                    puts("Truth");
                else
                    puts("Lie");
            
            } else
            {
                if (can.count(man[i]))
                    puts("Not defined");
                else
                    puts("Lie");
            }
        
        } else
        {
            if (sz(can) == 1)
            {
                if (man[i] == *can.begin())
                    puts("Lie");
                else
                    puts("Truth");
            
            } else
            {
                if (can.count(man[i]))
                    puts("Not defined");
                else
                    puts("Truth");
            }
        }
    }

    return 0;
}
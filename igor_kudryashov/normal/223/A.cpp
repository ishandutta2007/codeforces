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
int ansMax = -1, ansSt = -1, ansLen = -1;

void check (int lf, int rg)
{
    if (lf > rg) return;
    assert((rg - lf + 1) % 2 == 0);
    
    int cnt = 0;
    for (int i = lf; i <= rg; i++)
        cnt += (s[i] == '[');
        
    if (cnt > ansMax)
        ansMax = cnt, ansSt = lf, ansLen = rg - lf + 1;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    n = strlen(s);
    
    for (int st = 0; st < n; )
    {
        if (s[st] == ']' || s[st] == ')')
        {
            st++;
            continue;
        }
        
        vector <int> pos;
        pos.pb(st - 1);
        pos.pb(st);
        
        int i = st + 1;
        
        while (i < n)
        {
            if (s[i] == '(' || s[i] == '[')
                pos.pb(i++);
            else
            {
                if (sz(pos) == 1 || (s[pos.back()] == '[' && s[i] == ')') || (s[pos.back()] == '(' && s[i] == ']'))
                {
                    pos.pb(i);
                    break;
                }
                
                pos.pop_back();
                i++;
            }
        }
        
        if (i == n) pos.pb(i);
        
        forn(j, sz(pos) - 1)
            check(pos[j] + 1, pos[j + 1] - 1);
            
        st = i;
    }
    
    if (ansMax == -1)
        puts("0");
    else
    {
        printf("%d\n", ansMax);
        
        for (int i = ansSt; i < ansSt + ansLen; i++)
            putchar(s[i]);
            
        puts("");
    }
    
    return 0;
}
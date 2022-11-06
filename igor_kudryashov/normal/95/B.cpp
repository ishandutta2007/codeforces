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

char s[N];
int n;
char ans[N];

void writeStupid (int n)
{
    assert(n % 2 == 0);
    forn(i, n / 2)
        putchar('4');
    forn(i, n / 2)
        putchar('7');
    puts("");
    exit(0);
}

void write ()
{
    puts(ans);
    exit(0);
}

void rebuild (int pos)
{
    int cnt4 = 0, cnt7 = 0;
    forn(i, pos)
        cnt4 += ans[i] == '4', cnt7 += ans[i] == '7';
    
    int rem4 = n / 2 - cnt4, rem7 = n / 2 - cnt7;
    
    if (rem7 > 0)
    {
        int idx = -1;
        for (int i = pos - 1; i >= 0; i--)
        {
            rem4 += ans[i] == '4', rem7 += ans[i] == '7';
        
            if (ans[i] == '4')
            {
                idx = i;
                break;
            }
        }
            
        if (idx == -1)
            writeStupid(n + 2);
            
        int cur = idx;
        ans[cur++] = '7';
        rem7--;
        while (rem4 > 0)
            ans[cur++] = '4', rem4--;
        while (rem7 > 0)
            ans[cur++] = '7', rem7--;
        write();
    
    } else
    {
        int idx7 = -1;
        for (int i = pos - 1; i >= 0; i--)
            if (ans[i] == '7')
            {
                idx7 = i;
                break;
            }
        assert(idx7 != -1);
        
        int idx4 = -1;
        for (int i = idx7 - 1; i >= 0; i--)
            if (ans[i] == '4')
            {
                idx4 = i;
                break;
            }
            
        if (idx4 == -1)
            writeStupid(n + 2);
            
        rem4 = n / 2, rem7 = n / 2;
        ans[idx4] = '7';
        forn(i, idx4 + 1)
            rem4 -= ans[i] == '4', rem7 -= ans[i] == '7';
            
        int cur = idx4 + 1;
        while (rem4 > 0)
            ans[cur++] = '4', rem4--;
        while (rem7 > 0)
            ans[cur++] = '7', rem7--;
        write();
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    gets(s);
    n = strlen(s);
    
    if (n % 2 == 1)
        writeStupid(n + 1);

    int rem4 = n / 2, rem7 = n / 2;
    
    forn(i, n)
    {
        if (s[i] == '4')
        {
            if (rem4 > 0)
            {
                rem4--;
                ans[i] = '4';
                continue;
            }
            
            for (int j = i; j < n; j++)
                ans[j] = '7';
            write();
        
        } else if (s[i] == '7')
        {
            if (rem7 > 0)
            {
                rem7--;
                ans[i] = '7';
                continue;
            }
            rebuild(i);
        
        } else if (s[i] < '4')
        {
            int cur = i;
            while (rem4 > 0)
                ans[cur++] = '4', rem4--;
            while (rem7 > 0)
                ans[cur++] = '7', rem7--;
                
            write();
        
        } else if (s[i] > '7')
        {
            rebuild(i);
        
        } else
        {
            if (rem7 > 0)
            {
                ans[i] = '7';
                rem7--;
                int cur = i + 1;
                while (rem4 > 0)
                    ans[cur++] = '4', rem4--;
                while (rem7 > 0)
                    ans[cur++] = '7', rem7--;
                write();
            }
            rebuild(i);
        }
    }
    
    write();

    return 0;
}
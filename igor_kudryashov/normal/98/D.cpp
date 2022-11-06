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
#include <stack>
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
typedef pair <short, short> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = (1 << 20) + 13;

int n;
pt s[3][100];
int szs[3];
pt ans[N];
int szans;

void move (int fr, int to, int cnt)
{
    assert(szs[fr] >= cnt);

    forn(i, cnt)
    {
        s[to][szs[to]++] = s[fr][szs[fr] - 1];
        szs[fr]--;
        ans[szans++] = mp(fr, to);
    }
}

void go (int fr, int to, int cnt, bool stab)
{
    assert(szs[fr] >= cnt);
    
    if (cnt == 0)
        return;

    if (cnt == 1)
        return move(fr, to, 1);
    
    int freePos = -1;
    forn(i, 3)
        if (i != fr && i != to)
            freePos = i;
    assert(freePos != -1);
                
    int st = szs[fr] - cnt, fin = st, all = szs[fr];
    while (fin < szs[fr] && s[fr][st].ft == s[fr][fin].ft)
        fin++;
        
    if (stab)
    {
        if (fin == all)
        {
            move(fr, freePos, cnt - 1);
            move(fr, to, 1);
            move(freePos, to, cnt - 1);

        } else if (fin - st == 1)
        {
            go(fr, freePos, cnt - 1, false);
            go(fr, to, 1, true);
            go(freePos, to, cnt - 1, false);
            
        } else
        {
            go(fr, to, all - fin, false);
            move(fr, freePos, fin - st);
            go(to, fr, all - fin, false);
            move(freePos, to, fin - st);
            go(fr, to, all - fin, true);
        }
    
    } else
    {
        if (fin == all)
        {
            move(fr, to, cnt);
        
        } else
        {
            go(fr, freePos, all - fin, false);
            move(fr, to, fin - st);
            go(freePos, to, all - fin, false);
        }   
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    cin >> n;
    
    forn(i, n)
    {
        int a;
        scanf("%d", &a);
        s[0][szs[0]++] = mp(a, n - i);
    }
    
    go(0, 2, n, true);
    
    assert(szs[2] == n);
    forn(i, n - 1)
        assert(s[2][i] > s[2][i + 1]);
    
    cout << szans << endl;
    
    forn(i, szans)
        printf("%d %d\n", ans[i].ft + 1, ans[i].sc + 1);

    return 0;
}
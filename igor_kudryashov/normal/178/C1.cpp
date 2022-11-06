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

const int N = 200 * 1000 + 3;

int h, m, n;
int cntG;
vector <int> gr[N];
vector <int> t[N];
pt pos[N];
int used[N];
map <int, pt> idToPos;

int getPos (int numt, int idx, int lf, int rg, int pos)
{
    assert(pos >= lf);
    
    if (lf == rg)
        return t[numt][idx] == 1 ? -1 : lf;
    
    if (pos == lf)
    {
        if (t[numt][idx] == rg - lf + 1)
            return -1;
            
        int mid = (lf + rg) >> 1;
        
        if (t[numt][2 * idx + 1] != mid - lf + 1)
            return getPos(numt, 2 * idx + 1, lf, mid, lf);
            
        return getPos(numt, 2 * idx + 2, mid + 1, rg, mid + 1);
        
    } else
    {
        int mid = (lf + rg) >> 1;
        
        if (pos <= mid)
        {
            int res = getPos(numt, 2 * idx + 1, lf, mid, pos);
            if (res != -1) return res;
            return getPos(numt, 2 * idx + 2, mid + 1, rg, mid + 1);
        }
        
        return getPos(numt, 2 * idx + 2, mid + 1, rg, pos);
    }
}

void upd (int numt, int idx, int lf, int rg, int pos, int val)
{
    if (lf == rg)
    {
        assert(lf == pos);
        t[numt][idx] += val;
        return;
    }
    
    int mid = (lf + rg) >> 1;
    
    if (pos <= mid)
        upd(numt, 2 * idx + 1, lf, mid, pos, val);
    else
        upd(numt, 2 * idx + 2, mid + 1, rg, pos, val);
        
    t[numt][idx] = t[numt][2 * idx + 1] + t[numt][2 * idx + 2];
}

int add (int id, int hash)
{
    int numG = pos[hash].ft, posG = pos[hash].sc;
    
    int freePos = getPos(numG, 0, 0, sz(gr[numG]) - 1, posG);
    
    if (freePos == -1)
        freePos = getPos(numG, 0, 0, sz(gr[numG]) - 1, 0);
        
    assert(freePos != -1);
    
    idToPos[id] = mp(numG, freePos);
    
    upd(numG, 0, 0, sz(gr[numG]) - 1, freePos, 1);
    
    return (freePos - posG + sz(gr[numG])) % sz(gr[numG]);
}

void remove (int id)
{
    int numG = idToPos[id].ft, posG = idToPos[id].sc;
    idToPos.erase(id);
    upd(numG, 0, 0, sz(gr[numG]) - 1, posG, -1);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    scanf("%d %d %d\n", &h, &m, &n);
    
    forn(i, h)
    {
        if (used[i]) continue;
        
        int cur = i;
        while (!used[cur])
        {
            used[cur] = true;
            pos[cur] = mp(cntG, sz(gr[cntG]));
            gr[cntG].pb(cur);
            cur = (cur + m) % h;            
        }
        
        t[cntG].resize(sz(gr[cntG]) * 4);
        cntG++;
    }
    
    li ans = 0;
    
    forn(i, n)
    {
        char type;
        scanf("%c ", &type);
        
        if (type == '+')
        {
            int id, hash;
            scanf("%d %d\n", &id, &hash);
            ans += add(id, hash);
            
        } else
        {
            int id;
            scanf("%d\n", &id);
            remove(id);
        }
    }   
    
    cout << ans << endl;

    return 0;
}
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

const int N = 500 + 13;

int n;
int g[N][N];
int w[N][N];
int have[N], szhave;
int perm[N];

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;

    forn(i, n)
        forn(j, n)
            assert(scanf("%d", &g[i][j]) == 1);
            
    forn(i, n)
        assert(scanf("%d", &perm[i]) == 1), perm[i]--;
            
    return true;
}

li ans[N];
int tail, head, q[N], inq[N];

void bfs (int start, int d[N])
{
    tail = head = 0;
    q[tail++] = start;
    d[start] = 0;
    inq[start] = true;
    
    while (tail != head)
    {
        int v = q[head];
        if (++head == N) head = 0;
        inq[v] = false;
        
        forn(i, szhave)
        {
            int to = have[i];
            if (d[to] > d[v] + g[v][to])
            {
                d[to] = d[v] + g[v][to];
                if (!inq[to])
                {
                    inq[to] = true;
                    q[tail] = to;
                    if (++tail == N) tail = 0;
                }
            }
        }
    }
}

int V;

inline bool cmp (int i, int j)
{
    return w[i][V] < w[j][V];
}

inline void solve()
{
    //memset(w, 63, sizeof(w));
    forn(i, n) forn(j, n) w[i][j] = INF;
    
    ford(i, n)
    {
        have[szhave++] = perm[i];
        
        bfs(perm[i], w[perm[i]]);
        
        forn(j, szhave) w[perm[i]][have[j]] = min(w[perm[i]][have[j]], g[perm[i]][have[j]]);
        forn(j, szhave) w[have[j]][perm[i]] = min(w[have[j]][perm[i]], g[have[j]][perm[i]]);
        
        V = perm[i];
        sort(have, have + szhave - 1, cmp);
        
        forn(j, szhave)
            forn(k, szhave)
            {
                int a = have[j], b = have[k];
                w[a][perm[i]] = min(w[a][perm[i]], w[a][b] + w[b][perm[i]]);
            }

        forn(j, szhave)
            forn(k, szhave)
            {
                int a = have[j], b = have[k];
                w[a][b] = min(w[a][b], w[a][perm[i]] + w[perm[i]][b]);
            }
            
        forn(j, szhave)
            forn(k, szhave)
                ans[i] += w[have[j]][have[k]];

        /*forn(j, szhave) cerr << have[j] << ' '; cerr << endl; 
        forn(j, szhave)
        {
            forn(k, szhave) cerr << w[have[j]][have[k]] << ' ';
            cerr << endl;
        }
        cerr << endl;*/
    }
    
    forn(i, n)
        printf("%I64d ", ans[i]);
    puts("");
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
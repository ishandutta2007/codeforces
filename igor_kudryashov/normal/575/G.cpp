#ifdef MG
//#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

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

template<typename X> inline X abs(const X &a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X &a) { return a * a; }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = acosl(ld(-1));

const int N = 100 * 1000 + 13;

int n, m;
vector<pt> g[N];

inline bool read()
{
    if (scanf("%d%d", &n, &m) != 2)
        return false;
    
    forn(i, m) {
        int x, y, d;
        assert(scanf("%d%d%d", &x, &y, &d) == 3);
        
        g[x].pb(mp(y, d));
        g[y].pb(mp(x, d));
    }
    
    return true;
}

int d[2][N];

void bfs(int st, int d[N]) {
    queue<int> q;
    forn(i, n) d[i] = INF;
    
    q.push(st);
    d[st] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        forn(i, sz(g[v])) {
            int to = g[v][i].ft;
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

vector<int> nextq[10];

set<int> z[N];

int p[N];
int used[N];

void dfs(int v, int pr = -1) {
    if (used[v]) return;
    
    p[v] = pr;
    used[v] = true;
    
    forn(i, sz(g[v])) {
        int to = g[v][i].ft;
        int w = g[v][i].sc;
        
        if (w != 0) continue;
        
        dfs(to, v);
    }
}

void addPath(int v, vector<int> &path) {
    queue<int> q;
    vector<int> d(n, INF);
    vector<int> p(n, - 1);
    
    q.push(n - 1);
    d[n - 1] = 0;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        forn(i, sz(g[x])) {
            int to = g[x][i].ft;
            int w = g[x][i].sc;
            
            if (w != 0) continue;
            
            if (d[to] > d[x] + 1) {
                d[to] = d[x] + 1;
                q.push(to);
                p[to] = x;
            }
        }
    }
    
    reverse(all(path));
    
    for (v = p[v]; v != -1; v = p[v]) {
        path.pb(v);
    }
}

inline void solve()
{
    bfs(0, d[0]);
    bfs(n - 1, d[1]);
    
    vector<int> q;
    dfs(n - 1);
    
    int mind = INF;
    forn(i, n)
        if (used[i]) {
            if (d[0][i] < mind) {
                mind = d[0][i];
                q.clear();
            }
            
            if (d[0][i] == mind) {
                q.pb(i);
            }
        }
        
    string res;
    
    int it = 0;
    z[it++] = set<int>(all(q));
    
    while (true) {
        forn(i, 10) nextq[i].clear();
        
        forn(i, sz(q)) {
            int v = q[i];
            forn(j, sz(g[v])) {
                int to = g[v][j].ft;
                int w = g[v][j].sc;
                
                if (1 + d[0][to] == d[0][v]) {
                    nextq[w].pb(to);
                }
            }
        }
        
        q.clear();
        
        forn(i, 10) {
            if (!nextq[i].empty()) {
                res.pb(char('0' + i));
                q = nextq[i];
                break;
            }
        }
            
        if (q.empty()) {
            break;
        }
        
        sort(all(q));
        q.erase(unique(all(q)), q.end());
        
        z[it++] = set<int>(all(q));
    }
    
    it--;
    assert(it == sz(res));
    
    vector<int> t(1, 0);
    
    vector<int> nxt;
    
    ford(i, it) {
        nxt.clear();
        forn(j, sz(t)) {
            int v = t[j];
            
            forn(k, sz(g[v])) {
                int to = g[v][k].ft;
                int w = g[v][k].sc;
                
                if (d[0][v] + 1 == d[0][to] && w == int(res[i] - '0') && z[i].count(to)) {
                    nxt.pb(to);
                    p[to] = v;
                }
            }
        }
        
        t = nxt;
    }
    
    assert(!t.empty());
    
    int midv = -1;
    forn(i, sz(t)) {
        if (midv == -1 || d[1][midv] > d[1][t[i]]) {
            midv = t[i];
        }
    }
        
    vector<int> path;
    for (int v = midv; v != 0; v = p[v]) {
        path.pb(v);
    }
    path.pb(0);
    
    addPath(midv, path);
    
    if (res.empty()) res = "0";
    puts(res.c_str());
    
    cout << sz(path) << endl;
    forn(i, sz(path)) {
        printf("%d ", path[i]);
    }
    puts("");
}

int main()
{
#ifdef MG
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    srand(time(0));
    
    assert(read());
    solve();
    
#ifdef MG
    cerr << "=== TIME: " << clock() << " ===" << endl;
#endif

    return 0;
}
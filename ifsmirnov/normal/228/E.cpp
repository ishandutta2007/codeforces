#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 100500;

int n, m;
vi e[maxn], w[maxn];
int c[maxn];
void dfs(int v)
{
    forn(i, e[v].size())
    {
        int to = e[v][i];
        int w = ::w[v][i];
        int x = w ? c[v] : (3-c[v]);
        if (c[to] == 0)
        {
            c[to] = x;
            dfs(to);
        }
        else if (c[to] != x)
        {
            cout << "Impossible" << endl;
            exit(0);
        }
    }
}

int main()
{
    cin >> n >> m;
    forn(i, m)
    {
        int a, b, x;
        cin >> a >> b >> x;
        e[--a].pb(--b);
        e[b].pb(a);
        w[a].pb(x);
        w[b].pb(x);
    }
    forn(i, n) if (!c[i]) { c[i] = 1; dfs(i); }
    cout << count(c, c+n, 1) << endl;
    forn(i, n) if (c[i]==1) cout << i+1 << " "; cout << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
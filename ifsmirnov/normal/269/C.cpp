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
const int maxn = 200500;

int n, m;
vector<pii> e[maxn];
vi id[maxn];
int res[maxn];
int s[maxn], lft[maxn];
int q[maxn];

void scan()
{
    scanf("%d%d", &n, &m);
    forn(i, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[--u].pb(mp(--v, w));
        e[v].pb(mp(u, w));
        id[u].pb(i);
        id[v].pb(~i);
        s[u] += w;
        s[v] += w;
    }
    forn(i, n) lft[i] = s[i];
}

void solve()
{
    int lq = 0, rq = 0;
    q[rq++] = 0;
    while (lq != rq)
    {
        int v = q[lq++];
        forn(i, e[v].size())
        {
            int ne = id[v][i], to = e[v][i].fi, w = e[v][i].se;
            bool re = false;
            if (ne < 0) ne = ~ne, re = true;
            if (res[ne]) continue;
            res[ne] = 1 + re;
            lft[to] -= w;
            if (lft[to] * 2 == s[to] && to != n-1)
                q[rq++] = to;
        }
    }
    forn(i, m)
        printf("%d\n", !(res[i]%2));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
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

int n;
int a[maxn];
int d[maxn];
vi p[maxn];
vi f;

void factor(int x, int k, bool d)
{
    f.clear();
    for (int i = 2; i*i <= x; i++)
        if (x%i == 0)
        {
            while (x%i == 0) x /= i;
            if (d) p[i].pb(k);
            else p[i].pop_back();
            f.pb(i);
        }
    if (x != 1)
    {
        if (d) p[x].pb(k);
        else p[x].pop_back();
        f.pb(x);
    }
}

void scan()
{
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) factor(a[i], i, 1);
    fore(i, 2, 100000)
        reverse(all(p[i]));
}

void solve()
{
    forn(i, n)
    {
        d[i] = max(d[i], 1);
        factor(a[i], i, 0);
        forn(j, f.size()) if (!p[f[j]].empty())
            d[p[f[j]].back()] = max(d[p[f[j]].back()], d[i]+1);
    }
    int res = *max_element(d, d+n);
    printf("%d\n", res);
}

int main()
{
    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
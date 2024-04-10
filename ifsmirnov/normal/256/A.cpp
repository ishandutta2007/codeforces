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
const int maxn = 4050;

vi e[maxn];
int n;
int a[maxn];
vi diff;

void scan()
{
    cin >> n;
    forn(i, n) 
        cin >> a[i];
    diff = vi(a, a+n);
    sort(all(diff));
    diff.erase(unique(all(diff)), diff.end());
    forn(i, n) a[i] = lower_bound(all(diff), a[i]) - diff.begin();
    forn(i, n) e[a[i]].pb(i);
}

int solve(int a, int b)
{
    if (e[a][0] > e[b][0])
        return 0;
    int res = 0;
    int i = 0, j = 0, last = -1;
    while(1)
    {
        while (i < (int)e[a].size() && e[a][i] <= last)
            ++i;
        if ((int)e[a].size() == i)
            return res;
        ++res;
        last = e[a][i];
        swap(a, b);
        swap(i, j);
    }
}

void solve()
{
    int res = 0;
    forn(i, diff.size()) forn(j, diff.size())
        res = max(res, solve(i, j));
    cout << res << endl;
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
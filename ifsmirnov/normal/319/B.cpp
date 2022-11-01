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
int nxt[maxn], prv[maxn], b[maxn];
void rem(int i) {
    int n = nxt[i], p = prv[i];
    if (n != -1) prv[n] = p;
    if (p != -1) nxt[p] = n;
}
vi q, qq;

void scan()
{
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
}

void iter()
{
    forn(I, q.size()) {
        int i = q[I];
        assert(prv[i] != -1 && a[prv[i]] > a[i]);
        if (nxt[i] != -1 && a[nxt[i]] < a[prv[i]] && !b[nxt[i]])
            qq.pb(nxt[i]), b[nxt[i]] = 1;
        rem(i);
    }
    q = qq;
    qq.clear();
}

void solve()
{
    forn(i, n) {
        if (i) prv[i] = i-1;
        else prv[i] = -1;
        if (i != n-1) nxt[i] = i+1;
        else nxt[i] = -1;
    }

    ford(i, n) if (prv[i] != -1 && a[prv[i]] > a[i]) q.pb(i), b[i] = 1;

    int cnt = 0;
    while (!q.empty()) {
        iter();
        ++cnt;
    }

    printf("%d\n", cnt);
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
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
const int maxn = 2000500;

int n, l, t;
int a[maxn];
i64 res;

void scan()
{
    scanf("%d%d%d", &n, &l, &t);
    forn(i, n) scanf("%d", &a[i]);
    t *= 2;
}

void solve()
{
    sort(a, a+n);
    forn(i, n) a[i+n] = a[i]+l;

    // what to do with t/l?
    int tt = t/l;
    //cout << "tt = " << tt << endl;
    t %= l;

    for (int i = 0, j = 0; i < n; i++) {
        if (j < i) j = i;
        while (j < n*2 && a[j] <= a[i]+t) ++j;
        res += j-i-1;
        res += (i64)tt * (n-1);
        //cout << i << " " << j << endl;
    }

    cout.precision(10);
    cout << fixed;
    cout << res/4 << ".";
    if (res%4 == 0) cout << "00";
    if (res%4 == 1) cout << "25";
    if (res%4 == 2) cout << "50";
    if (res%4 == 3) cout << "75";
    cout << endl;
}

void gen()
{
    freopen("input.txt", "w", stdout);
    int n = 10000, l = 10000, t = 1000000000;
    cout << n << " " << l << " " << t << endl;
    forn(i, n) cout << i << " "; cout << endl;
    exit(0);
}

int main()
{
    //gen();
    //freopen("input.txt", "r", stdin);

    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
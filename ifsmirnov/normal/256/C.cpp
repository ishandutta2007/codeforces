#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
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

const int K = 10;

int sp[900000][K];

i64 mpow(i64 x, int k)
{
    i64 t = 1;
    forn(i, k) t *= x;
    return t;
}
void getlr(i64 x, int &l, int &r)
{
    l = max((int)sqrt(sqrt(x)) - 5, 0);
    while (mpow(l, 4) < x)
        ++l;
    r = sqrt(x) + 5;
    while (mpow(r, 2) > x)
        --r;
    if (r >= x)
        r = x-1;
}

int tgr[10];

int mmx = 0;
int get(i64 x)
{
    if (x == 1)
        return 0;
    int l, r;
    getlr(x, l, r);
    int t = 0;
    while (sp[r][t] > sp[l-1][t])
        ++t;
    return t;
}

void precomp()
{
    fore(i, 1, 899900)
    {
        int t = get(i);
        forn(k, K)
            sp[i][k] = sp[i-1][k] + (t == k);
    }
}

void solve()
{
    precomp();
    int n;
    int x = 0;
    cin >> n;
    forn(i, n)
    {
        i64 t;
        cin >> t;
        x ^= get(t);
    }
    cout << (x ? "Furlo" : "Rublo") << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
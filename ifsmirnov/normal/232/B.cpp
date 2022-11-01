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
const int maxn = 105;

const int mod = 1e9+7;
int add(int x, int y) { return (i64)(x+y)%mod; }
int mul(int x, int y) { return (i64)x*y%mod; }
int mpow(int x, i64 k)
{
    if (k == 0) return 1;
    int t = mpow(mul(x,x), k/2);
    if (k%2) t = mul(t, x);
    return t;
}

int cnk[maxn][maxn];
void init()
{
    cnk[0][0] = 1;
    fore(i, 1, 100)
    {
        cnk[i][0] = 1;
        fore(j, 1, i) cnk[i][j] = add(cnk[i-1][j], cnk[i-1][j-1]);
    }
}

int n, k;
i64 m;

int d[maxn][maxn*maxn];
int premul[maxn][maxn];
i64 ppow[maxn];

void solve()
{
    forn(i, n) ppow[i] = m/n + (i < m%n);
    forn(i, n) forn(j, n+1) premul[i][j] = mpow(cnk[n][j], ppow[i]);
    d[0][0] = 1;
    forn(i, n) fore(j, 0, k) fore(p, 0, min(n, k-j))
        d[i+1][j+p] = add(d[i+1][j+p], mul(d[i][j], premul[i][p]));
    cout << d[n][k] << endl;
}

int main()
{
    //freopen("input.txt", "r",stdin);
    init();
    cin >> n >> m >> k;
    //n = 100;
    //m = 1000000000000000000;
    //k = 10000;
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
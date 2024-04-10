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
const int maxn = 505;

i64 p = 10099, q = 424243;
i64 pp[maxn], pq[maxn];

int n, m;
int a[maxn][maxn];
i64 h[maxn][maxn];

void buildh()
{
    forn(i, n) forn(j, m)
    {
        h[i][j] = a[i][j]+8;
        if (i) h[i][j] += p*h[i-1][j];
        if (j) h[i][j] += q*h[i][j-1];
        if (i&&j) h[i][j] -= p*q*h[i-1][j-1];
    }
    pp[0] = pq[0] = 1;
    forn(i, maxn) if (i)
    {
        pp[i] = pp[i-1]*p;
        pq[i] = pq[i-1]*q;
    }
}
i64 geth(int x1, int y1, int x2, int y2)
{
    i64 s = h[x2][y2];
    if (x1) s -= h[x1-1][y2] * pp[x2-x1+1];
    if (y1) s -= h[x2][y1-1] * pq[y2-y1+1];
    if (x1&&y1) s += h[x1-1][y1-1] * pp[x2-x1+1] * pq[y2-y1+1];
    return s;
}
i64 th[maxn][maxn];
i64 geth(const vector<vi> &a)
{
    int n = a.size();
    //if (n > 4) return 0;
    forn(i, n) forn(j, n)
    {
        //cout << a[i][j];
        //if (j == n-1) cout << endl;
        th[i][j] = a[i][j]+8;
        if (i) th[i][j] += p*th[i-1][j];
        if (j) th[i][j] += q*th[i][j-1];
        if (i&&j) th[i][j] -= p*q*th[i-1][j-1];
    }
    //cout << endl;
    return th[n-1][n-1];
}
map<i64, int> frac;
void buildFracs()
{
    bool f[2][2];
    forn(mask, 16)
    {
        f[0][0] = mask&1;
        f[0][1] = mask&2;
        f[1][0] = mask&4;
        f[1][1] = mask&8;
        vector<vi> a(2, vi(2));
        forn(i, 2) forn(j, 2) a[i][j] = f[i][j];
        int n = 2;
        while (n < 250)
        {
            vector<vi> b(n*2, vi(n*2, 0));
            forn(i, 2) forn(j, 2)
            {
                if (f[i][j])
                {
                    forn(x, n) forn(y, n) b[i*n+x][j*n+y] = 1;
                }
                else
                {
                    forn(x, n) forn(y, n) b[i*n+x][j*n+y] = a[x][y];
                }
            }
            frac[geth(b)]++;
            a = b;
            n *= 2;
        }
    }
}

void scan()
{
    cin >> n >> m;
    char t[maxn];
    forn(i, n)
    {
        cin >> t;
        forn(j, m) a[i][j] = t[j] == '*';
    }
}
void solve()
{
    buildh();
    int s = 0;
    for (int a = 4; a < 500; a *= 2)
        forn(i, n-a+1) forn(j, m-a+1)
            s += frac[geth(i, j, i+a-1, j+a-1)];
    cout << s << endl;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    buildFracs();
    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
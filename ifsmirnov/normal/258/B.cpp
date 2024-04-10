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
const int mod = 1000000007;
int add(int x, int y) { return (x+y)%mod; }
int mul(int x, int y) { return (i64)x*y%mod; }
int mpow(int x, int k)
{
    if (k == 0) return 1;
    if (k == 1) return x;
    int t = mpow(mul(x, x), k/2);
    if (k%2) t = mul(t, x);
    return t;
}

int cnk[20][20];
void initcnk()
{
    cnk[0][0] = 1;
    forn(i, 20) if (i)
        forn(j, i+1)
        {
            cnk[i][j] = cnk[i-1][j];
            if (j) cnk[i][j] = add(cnk[i][j], cnk[i-1][j-1]);
        }
}

int len(int x)
{
    int t = 0;
    while (x/10)
        ++t, x /= 10;
    return t;
}
int getl(int x)
{
    int res = 0;
    while (x)
    {
        res += x%10 == 7 || x%10 == 4;
        x /= 10;
    }
    return res;
}

int cnt[20];
int rcnt[20];
void cadd(int i, int x)
{
    cnt[i] = add(cnt[i], x);
    rcnt[i] = max(rcnt[i] + x, 100);
}

void god(int x)
{
    fore(i, 1, x)
        cadd(getl(i), 1);
}
void go(int x, int offset)
{
    //cout << x << " " << offset << endl;
    int n = len(x);
    int p = mpow(10, n);
    if (n == 0)
    {
        int r0 = x+1;
        int r1 = (x >= 4) + (x >= 7);
        r0 -= r1;
        cadd(0+offset, r0);
        cadd(1+offset, r1);
        return;
    }
    go(x%p, offset + (x/p == 4 || x/p == 7));
    forn(fd, x/p)
    {
        fore(k, 0, n)
        {
            int res = mul(cnk[n][k], mul(mpow(2, k), mpow(8, n-k)));
            cadd(k + offset + (fd == 4 || fd == 7), res);
        }
    }
}

int mgo(int pos, int cur, int lim)
{
    if (pos == 6)
        return cur;
    int res = 0;
    forn(i, lim) if (rcnt[i])
    {
        --rcnt[i];
        int t = cnt[i];
        cadd(i, mod-1);
        res = add(res, mgo(pos+1, mul(cur, t), lim-i));
        ++rcnt[i];
        cadd(i, 1);
    }
    return res;
}

void solve()
{
    int res = 0;
    fore(i, 1, 10) if (rcnt[i])
    {
        --rcnt[i];
        int t = cnt[i];
        cadd(i, mod-1);
        res = add(res, mgo(0, t, i));
        ++rcnt[i];
        cadd(i, 1);
    }
    cout << res << endl;
}

int main()
{
    initcnk();

    int m;
    cin >> m;
    go(m, 0);
    cnt[0] = (cnt[0]+mod-1)%mod;
    --rcnt[0];
    //forn(i, 10) cout << cnt[i] << " "; cout << endl;

    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
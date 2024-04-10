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

vector<int> factor(int n)
{
    vi res;
    for (int i = 1; i*i <= n; i++)
        if (n%i == 0)
        {
            res.pb(i);
            if (i*i != n)
                res.pb(n/i);
        }
    sort(all(res));
    return res;
}

int n;
int a[maxn];
int mx;

void scan()
{
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    sort(a, a+n);
    mx = a[n-1];
}

int get(int m)
{
    //cout << m << endl;
    vi f = factor(m);
    int res = 1;
    int pos = -1;
    forn(i, f.size())
    {
        int d = f[i];
        int np = lower_bound(a, a+n, d) - a - 1;
        if (i)
            res = mul(res, mpow(i, np-pos));
        //cout << i << ": " << np-pos << endl;
        pos = np;
    }
    int fs = f.size();
    int k = n-1-pos;
    res = mul(res, ((i64)mpow(fs, k) - mpow(fs-1, k) + mod)%mod);
    //cout << f.size() << ": " << n-1-pos << endl;
    return res;
}

void solve()
{
    int res = 0;
    fore(i, 1, mx)
        res = add(res, get(i));
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
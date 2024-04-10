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

#define y1 fdsfds

int gcd(int a, int b)
{
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

#define sqr(x) ((x)*(x))

int n, m, a, b, g, x, y, w, h;
int x1=inf, y1;
i64 dist(int x1, int y1) {
    return sqr((i64)(x1+x1+w-2*x)) + sqr((i64)(y1+y1+h-2*y));
}

void relax(int X1, int Y1)
{
    i64 curd = x1 == inf ? (i64)inf*inf : dist(x1, y1);
    i64 newd = dist(X1, Y1);

    if (x1 == inf || (newd < curd || (newd == curd && mp(X1, Y1) < mp(x1, y1))))
        x1=X1, y1=Y1;
}

void shift(int x, int y)
{
    int dx = 0, dy = 0;
    if (x < 0) dx = -x;
    else if (x+w > n) dx = n-(x+w);
    if (y < 0) dy = -y;
    else if (y+h > m) dy = m-(y+h);
    x += dx; y += dy;
    //cout << x << " " << y << ": " << dist(x, y) << endl;
    relax(x, y);
}

void scan()
{
    cin >> n >> m >> x >> y >> a >> b;
    g = gcd(a, b);
    a /= g; b /= g;
}

void solve()
{
    int cf = min(n/a, m/b);
    w = cf*a, h = cf*b;

    //cout << w << " " << h << endl;

    
    fore(dx, -3, 3) fore(dy, -3, 3)
        shift(x-w/2+dx, y-h/2+dy);

    cout << x1 << " " << y1 << " " << x1+w << " " << y1+h << endl;
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
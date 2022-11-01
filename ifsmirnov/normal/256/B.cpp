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

i64 n, x, y, c;
i64 get(i64 d)
{
    i64 res = 2*(d*d-d) + 1;
    forn(I, 4)
    {
        i64 k = d - y - 1;
        i64 l = k - x - 1;
        if (k > 0)
        {
            res -= k*k;
            if (l > 0)
                res += l*(l+1)/2;
        }
        int ty = n-x-1;
        int tx = y;
        y = ty;
        x = tx;
    }
    return res;
}

void solve()
{
    cin >> n >> x >> y >> c;
    --x, --y;
    i64 l = 0, r = 100000000, m;
    while (r-l > 1)
    {
        m = (r+l)/2;
        if (get(m) >= c)
            r = m;
        else
            l = m;
    }
    cout << r-1 << endl;
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
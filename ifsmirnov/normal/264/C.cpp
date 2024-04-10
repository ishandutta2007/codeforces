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
typedef pair<i64, int> pii;
typedef vector<int> vi;
const i64 inf = 1e18+100500;
const int maxn = 100500;

int n, q;
i64 v[maxn];
int c[maxn];
i64 mx[maxn];

void scan()
{
    cin >> n >> q;
    forn(i, n) cin >> v[i];
    forn(i, n) cin >> c[i], --c[i];
}
i64 get(i64 a, i64 b)
{
    pii m1 = mp(0, -1);
    pii m2 = mp(0, -1);
    forn(i, n) mx[i] = -inf;
    forn(i, n)
    {
        i64 t = b * v[i];
        if (m1.se != c[i]) t += m1.fi;
        else t += m2.fi;
        if (mx[c[i]] != -inf)
            t = max(t, mx[c[i]] + a*v[i]);
        mx[c[i]] = max(mx[c[i]], t);
        
        pii p = mp(t, c[i]);
        
        if (p.fi > m1.fi)
        {
            if (p.se == m1.se)
                m1.fi = p.fi;
            else
            {
                m2 = m1;
                m1 = p;
            }
        }
        else if (p.fi > m2.fi)
        {
            if (p.se == m2.se)
                m2.fi = p.fi;
            else if (p.se == m1.se)
                ;
            else
                m2 = p;
        }
    }

    return m1.fi;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    scan();
    forn(i, q)
    {
        int a,b;
        cin >> a >> b;
        cout << get(a,b) << endl;
    }

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
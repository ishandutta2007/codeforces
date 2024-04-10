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

char zig[maxn][7][10];
int n;
void genZigs()
{
    int n = maxn;
    fore(z, 2, 6)
    {
        forn(i, n)
        {
            int t = (i+1)%(2*z-2);
            if (t == 0)
                zig[i][z][0] = 2;
            else if (t <= z)
                zig[i][z][0] = t;
            else
                zig[i][z][0] = 2*z-t;
        }
        for (int p = 1; p < 2*z-2; p++)
            fore(i, p, n-1)
                zig[i][z][p] = zig[i-p][z][0];
    }
}
i64 fen[maxn][7][20];
void add(int i, i64 x, int b, int c)
{
    for (; i < maxn; i |= (i+1))
        fen[i][b][c] += x;
}
i64 get(int i, int b, int c)
{
    i64 s = 0;
    for (; i >= 0; i = (i&(i+1))-1)
        s += fen[i][b][c];
    return s;
}
i64 get(int l, int r, int b, int c)
{
    return get(r, b, c) - (l ? get(l-1, b, c) : 0);
}

int a[maxn];

void mset(int i, int x)
{
    fore(z, 2, 6) fore(p, 0, z*2-3)
        add(i, (i64)(x-a[i])*(i64)zig[i][z][p], z, p);
    a[i] = x;
}
i64 mget(int l, int r, int z)
{
    return get(l, r, z, l%(z*2-2));
}

void solve()
{
    cin >> n;
    genZigs();    
    //fore(z, 2, 6)
    //{
        //forn(p, 2*z-2)
        //{
            //forn(i, n) cout << zig[i][z][p] << " ";
            //cout << endl;
        //}
        //cout << endl;
    //}
    //cout << endl;
    forn(i, n)
    {
        int x;
        cin >> x;
        mset(i, x);
    }
    int m;
    cin >> m;
    forn(i, m)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p, v;
            cin >> p >> v;
            mset(p-1, v);
        }
        else
        {
            int l, r, z;
            cin >> l >> r >> z;
            cout << mget(l-1, r-1, z) << "\n";
        }
    }
}
void gen()
{
    freopen("input.txt", "w", stdout);
    int n = 100000;
    cout << n << endl;
    forn(i, n) cout << rand() << " "; cout << endl;
    cout << n << endl;
    forn(i, n)
    {
        if (rand()%2)
        {
            cout << 1 << " " << rand()%n+1 << " " << rand() << endl;
        }
        else
        {
            int l = rand()%n, r = rand()%n;
            if (l>r) swap(l, r);
            cout << 2 << " " << l+1 << " " << r+1 << " " <<rand()%5+2 << endl;
        }
    }
    exit(0);
}
int main()
{
    //gen();
    //freopen("input.txt", "r", stdin);
    //freopen("/dev/null", "w", stdout);
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
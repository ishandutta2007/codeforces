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
const int maxn = 55;

int na, ma, nb, mb;
int a[maxn][maxn], b[maxn][maxn];
int f(int x, int y)
{
    int s = 0;
    forn(i, na) forn(j, ma) if (i+x >= 0 && i+x < nb && j+y >= 0 && j+y < mb)
        s += a[i][j]*b[i+x][j+y];
    return s;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    char t[maxn];
    cin >> na >> ma;
    forn(i, na)
    {
        cin >> t;
        forn(j, ma) a[i][j] = (t[j] == '1');
    }
    cin >> nb >> mb;
    forn(i, nb)
    {
        cin >> t;
        forn(j, mb) b[i][j] = (t[j] == '1');
    }
    int best = 0;
    int bx = 0, by = 0;
    fore(x, -51, 51) fore(y, -51, 51)
    {
        int q = f(x, y);
        if (q > best)
            bx = x, by = y, best = q;
    }
    cout << bx << " " << by << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
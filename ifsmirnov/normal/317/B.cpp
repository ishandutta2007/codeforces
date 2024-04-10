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
const int maxn = 134;

#define ok(x, y) ((x)>=0 && (y)>=0 && (x)<maxn && (y)<maxn)

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int a[maxn][maxn], nxt[maxn][maxn];
int n = maxn;


bool iter2()
{
    bool upd = false;
    forn(i, maxn) forn(j, maxn) {
        int t = a[i][j] / 4;
        if (t) {
            upd = true;
            a[i][j] -= 4*t;
            forn(k, 4) a[i+dx[k]][j+dy[k]] += t;
        }
    }
    return upd;
}

int h = 0;

int solve(int n)
{
    forn(i, maxn) forn(j, maxn) a[i][j] = 0;
    a[maxn/2][maxn/2] = n;

    int cnt = 0;
    while (iter2()) ++cnt;

    int mxx = -1, mxy = -1, mnx = 100000, mny = 100000;
    forn(i, maxn) forn(j, maxn) if (a[i][j]) {
        mxx = max(mxx, i); mnx = min(mnx, i);
        mxy = max(mxy, j); mny = min(mny, j);
    }

    //cerr << mnx << " " << mxx << "    " << mny << " " << mxy << endl;
    //cerr << mxx - mnx << endl;

    //cout << " ---- " << n << " ----" << endl;
    //fore(i, mnx, mxx) {
        //fore(j, mny, mxy) cout << a[i][j] << " ";
        //cout << endl;
    //}
    //cout << endl;

    forn(i, maxn) forn(j, maxn) h = h * 10099  + a[i][j] * 179;

    return cnt;
}

void gen()
{
    freopen("input.txt", "w", stdout);
    cout << 30000 << " " << 50000 << endl;
    forn(i, 50000) cout << rand()%1000 << " " << rand()%1000 << endl;
}

int main()
{
    //gen();
    //freopen("input.txt", "r", stdin);
    //freopen("/dev/null", "w", stdout);
    int n;
    scanf("%d", &n);
    solve(n);
    int t;
    scanf("%d", &t);
    forn(i, t) {
        int x, y;
        scanf("%d%d", &x, &y);
        x += maxn/2; y += maxn/2;
        if (ok(x, y)) printf("%d\n", a[x][y]);
        else printf("0\n");
    }
    //for (int i = 1; i <= 100; i++)
        //cout << i << ": " << solve(i) << endl;

    //cout << h << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
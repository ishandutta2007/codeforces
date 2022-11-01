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
const int maxn = 550;

int n;
int e[maxn][maxn];
vector<vi> cur, nxt;
int order[maxn];
i64 res[maxn];

void scan()
{
    scanf("%d", &n);
    forn(i, n) {
        forn(j, n) scanf("%d", &e[i][j]);
    }
    nxt.assign(n, vi(n, 0));
    forn(i, n) forn(j, n) nxt[i][j] = e[i][j];
    forn(i, n) {
        scanf("%d", &order[i]);
        --order[i];
    }
}

void out(const vector<vi> &a) {
    forn(i, n) {
        forn(j, n) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void solve()
{
    reverse(order, order+n);
    forn(K, n) {

        swap(cur, nxt);
        nxt = cur;

        int k = order[K];
        forn(i, n) forn(j, n) {
            nxt[i][j] = min(nxt[i][j], cur[i][k] + cur[k][j]);
        }

        i64 res = 0;
        forn(i, K+1) forn(j, K+1) {
            res += nxt[order[i]][order[j]];
        }
        ::res[K] = res;
    }
    ford(i, n) {
        cout << ::res[i] << " ";
    }
    cout << endl;
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
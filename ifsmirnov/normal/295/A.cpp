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

int n, m, k;
i64 l[maxn], r[maxn], d[maxn];
i64 s[maxn], t[maxn];
int a[maxn];

void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    forn(i, m) {
        int q, w, e;
        scanf("%d%d%d", &q, &w, &e);
        l[i] = q-1;
        r[i] = w-1;
        d[i] = e;
    }
    forn(i, k) {
        int q, w;
        scanf("%d%d", &q, &w);
        --q; --w;
        t[q]++; t[w+1]--;
    }
    i64 cnt = 0;
    forn(i, m) {
        cnt += t[i];
        s[l[i]] += cnt * d[i];
        s[r[i]+1] -= cnt * d[i];
    }

    i64 res = 0;
    forn(i, n) {
        res += s[i];
        cout << res + a[i] << " ";
    }
    cout << endl;
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
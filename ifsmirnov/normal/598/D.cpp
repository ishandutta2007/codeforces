#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 1050;

int n, m;
char c[maxn][maxn];
int a[maxn][maxn], res[maxn * maxn];

int dfs(int x, int y, int c) {
    if (::c[x][y] == '*') return 1;
    if (a[x][y]) return 0;
    a[x][y] = c;
    int s = 0;
    s += dfs(x-1, y, c);
    s += dfs(x+1, y, c);
    s += dfs(x, y-1, c);
    s += dfs(x, y+1, c);
    return s;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int q;
    cin >> n >> m >> q;
    forn(i, n) cin >> c[i];
    int nc = 0;
    forn(i, q) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (!a[x][y]) {
            ++nc;
            res[nc] = dfs(x, y, nc);
        }
        cout << res[a[x][y]] << "\n";
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
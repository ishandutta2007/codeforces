#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <tgmath.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define int long long
using namespace std;
const int N = 600 + 12;
const ld PI = 3.141592653589793238;
const int inf = 1e18;

bool local = 0;

int d[N][N];
bool good[N][N];
int ed[N][N];
int dl[N][N];
void solve() {
    int n, k, a, b, w;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            d[i][j] = inf;
            ed[i][j] = inf;
            dl[i][j] = 0;
        }
    for (int i = 0;  i< n; ++i)
        d[i][i] = 0;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b >> w;
        --a;
        --b;
        d[a][b] = w;
        d[b][a] = w;
        ed[a][b] = w;
        ed[b][a] = w;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        cin >> dl[u][v];
        dl[v][u] = dl[u][v];
    }
    for (int l = 0; l < n; ++l)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
    for (int l = 0; l < n; ++l)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dl[i][j] = max(dl[i][j], max(-d[i][l] + dl[l][j], dl[i][l] - d[l][j]));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        if (i != j) {
            good[i][j] = ed[i][j] <= dl[i][j];
        }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (good[i][j] || good[j][i])
                ++cnt;
    cout << cnt << "\n";
}


signed main() {
    if (local) {
        freopen("input.txt", "r", stdin);
    }
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
}
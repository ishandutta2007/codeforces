#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int inf = 1e8;
int n, m;
vector<char> grid[1000000];
int idx(int x, int y) {
    return x * (m + 1) + y;
}

int d[2100000];
bool vis[2100000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        grid[i].resize(m + 1);
        cin >> grid[i].data();
    }
    for (int i = 0; i < 2100000; ++i) d[i] = inf;
    deque<int> q;
    for (int i = 1; i <= m; ++i) {
        int x = idx(0, i);
        q.push_back(x);
        d[x] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int x = idx(i, m);
        q.push_back(x);
        d[x] = 0;
    }
    int ans = inf;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (vis[v]) continue;
        vis[v] = 1;
        int x = v / (m + 1);
        int y = v % (m + 1);
        if (x > 0) {
            int nv = idx(x - 1, y);
            if (d[v] < d[nv]) {
                q.push_front(nv);
                d[nv] = d[v];
            }
        }
        if (y < m) {
            int nv = idx(x, y + 1);
            if (d[v] < d[nv]) {
                q.push_front(nv);
                d[nv] = d[v];
            }
        }
        if (x == n || y == 0) ans = min(ans, d[v]);
        if (x < n && y > 0) {
            int tx = x;
            int ty = y - 1;
            if (tx == 0 && ty == 0) continue;
            if (tx == n - 1 && ty == m - 1) continue;
            int nv = idx(x + 1, y - 1);
            if (grid[tx][ty] == '.') {
                if (d[v] + 1 < d[nv]) {
                    q.push_back(nv);
                    d[nv] = d[v] + 1;
                }
            }
            else {
                if (d[v] < d[nv]) {
                    q.push_front(nv);
                    d[nv] = d[v];
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);
const int N = 203222;
vector<int> g[N], gg[N];
int d[N];
int f[N], h[N];
int parent[N];

int main() {
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        gg[y].push_back(x);
        parent[y] = x;
        d[x]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (d[i] == 0) {
            q.push(i);
            ++m;
        }
    vector<int> order;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        order.push_back(x);
        for (int y : gg[x]) {
            --d[y];
            if (!d[y]) q.push(y);
        }
    }

    for (int i = n - 2; i >= 0; --i)
        h[order[i]] = h[parent[order[i]]] + 1;

    for (int x : order) {
        if (g[x].size() == 0) {
            f[x] = 1;
            continue;
        }

        if (h[x] & 1) {
            f[x] = 0;
            for (int y : g[x]) {
                f[x] += f[y];
            }
        } else {
            f[x] = 1e9;
            for (int y : g[x]) {
                f[x] = min(f[x], f[y]);
            }
        }
    }

    cout << m - f[1] + 1 << ' ';

    for (int x : order) {
        if (g[x].size() == 0) {
            f[x] = 1;
            continue;
        }

        if (h[x] & 1) {
            f[x] = 1e9;
            for (int y : g[x]) {
                f[x] = min(f[x], f[y]);
            }
        } else {
            f[x] = 0;
            for (int y : g[x]) {
                f[x] += f[y];
            }
        }
    }

    cout << f[1] << endl;

    return 0;
}
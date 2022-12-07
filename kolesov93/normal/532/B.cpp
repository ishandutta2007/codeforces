#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 300222;
vector<int> g[N];
int a[N];
ll f[N][2];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        if (x > 0)
            g[x].push_back(i);
        scanf("%d", a + i);
    }

    for (int x = n; x; --x) {
        f[x][0] = 0;
        f[x][1] = a[x];

        ll sum = 0;
        priority_queue<ll> q;
        for (int y : g[x]) {
            sum += f[y][0];
            q.push(f[y][1] - f[y][0]);
        }

        f[x][0] = max(f[x][0], sum);
        f[x][1] = max(f[x][1], sum + a[x]);
        int parity = 0;
        while (!q.empty()) {
            parity ^= 1;
            ll cost = q.top(); q.pop();

            sum += cost;
            if (parity == 1) {
                f[x][1] = max(f[x][1], sum);
            } else {
                f[x][0] = max(f[x][0], sum);
                f[x][1] = max(f[x][1], sum + a[x]);
            }
        }
    }
    cout << max(f[1][0], f[1][1]) << endl;

    return 0;
}
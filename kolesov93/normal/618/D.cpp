#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
const int N = 200222;
vector<int> g[N];
bool used[N];
vector<int> sons[N];
ll f[N][3], F[N];

void dfs(int x) {
    used[x] = true;
    for (int y : g[x]) {
        if (!used[y]) { 
            dfs(y);
            sons[x].push_back(y);
        }
    }

    f[x][0] = 0;
    ll cur1 = 1e9;
    ll cur2 = 1e9;
    for (int y : sons[x]) {
        f[x][0] += F[y];

        int diff = F[y] - max(f[y][0], f[y][1]);
        if (diff < cur2) {
            cur2 = diff;
        }
        if (cur1 > cur2) {
            swap(cur1, cur2);
        }
    }

    f[x][1] = -1e9;
    f[x][2] = -1e9;
    if (cur1 < 1e8) {
        f[x][1] = f[x][0] - cur1 + 1;
    }
    if (cur2 < 1e8) {
        f[x][2] = f[x][0] - cur1 - cur2 + 2;
    }
    F[x] = max(f[x][0], max(f[x][1], f[x][2]));
}

int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (n == 2) {
        cout << x << endl;
        return 0;
    }
    if (n == 3) {
        cout << min(x + x, y + x) << endl;
        return 0;
    }
    if (x == y) {
        cout << ll(x) * (n - 1) << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    if (x > y) {
        bool cool = true;
        for (int i = 0; i < n; ++i)
            if (int(g[i].size()) == n - 1) {
                cool = false;
                break;
            }

        if (cool) cout << ll(y) * (n - 1) << endl;
        else cout << ll(y) * (n - 2) + x << endl;
        return 0;
    }

    dfs(0);
    cout << ll(x) * F[0] + ll(y) * (n - 1 - F[0]) << endl;

    return 0;
}
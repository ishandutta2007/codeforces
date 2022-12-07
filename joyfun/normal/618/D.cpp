#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 200005;

int n;
ll x, y;
vector<int> g[N];
int cnt;

int dfs(int u, int p) {
    int tmp = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        if (dfs(v, u)) {
            cnt++;
            tmp++;
        }
    }
    if (tmp >= 2) {
        cnt--;
        return 0;
    } else if (tmp == 1) {
        cnt--;
        return 1;
    }
    return 1;
}

ll solve() {
    if (n == 1) return 0;
    if (x >= y) {
        for (int i = 1; i <= n; i++) {
            if (g[i].size() == n - 1)
                return x + y * (n - 2);
        }
        return y * (n - 1);
    }
    cnt = 0;
    if (dfs(1, 1)) cnt++;
    //printf("%d\n", cnt);
    return y * (cnt - 1) + (n - cnt) * x;
}

int main() {
    scanf("%d%lld%lld", &n, &x, &y);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    printf("%lld\n", solve());
    return 0;
}
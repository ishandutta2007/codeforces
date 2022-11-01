#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

constexpr int maxa = 200000;

int a[200000];
vector<int> adj[200000];
bool vis[200000];

vector<int> ra[maxa + 1];
long long ans[maxa + 1];

int dfs(int v) {
    vis[v] = true;

    int cnt = 1;
    for (int c : adj[v])
        if (!vis[c])
            cnt += dfs(c);
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        ra[a[i]].push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    fill_n(vis, n, true);

    for (int i = maxa; i >= 1; i--) {
        for (int j = i; j <= maxa; j += i)
            for (int v : ra[j])
                vis[v] = false;
        long long cnt = 0;
        for (int j = i; j <= maxa; j += i)
            for (int v : ra[j])
                if (!vis[v]) {
                    int nc = dfs(v);
                    cnt += nc * (nc + 1LL) / 2;
                }
        for (int j = i * 2; j <= maxa; j += i)
            cnt -= ans[j];
        ans[i] = cnt;
    }

    for (int i = 1; i <= maxa; i++)
        if (ans[i])
            printf("%d %lld\n", i, ans[i]);
}
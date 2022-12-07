#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int N = 500005;

int n;
vector<int> g[N], ans;

void dfs(int u, int p, int d) {
    int flag = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        flag = 1;
        dfs(v, u, d + 1);
    }
    if (!flag) ans.push_back(d);
}

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int out = 0;
    for (int i = 0; i < g[1].size(); i++) {
        ans.clear();
        dfs(g[1][i], 1, 0);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j++) {
            if (j && ans[j] <= ans[j - 1])
                ans[j] = ans[j - 1] + 1;
        }
        out = max(out, ans[ans.size() - 1] + 1);
    }
    printf("%d\n", out);
    return 0;
}